# Created by: koshy@india.hp.com
# $FreeBSD$

PORTNAME=	mhonarc
PORTVERSION=	2.6.18
PORTREVISION=	1
CATEGORIES=	www mail
MASTER_SITES=	http://www.mhonarc.org/release/MHonArc/tar/ \
		http://www.oac.uci.edu/indiv/ehood/tar/
DISTNAME=	MHonArc-${PORTVERSION}

MAINTAINER=	kerndtr@kerndt.com
COMMENT=	WWW front end for mail archives

USES=		tar:bzip2 perl5
NO_BUILD=	Yes

INSTALL_ARGS=	-prefix ${STAGEDIR} -binpath ${STAGEDIR}${PREFIX}/bin \
		-libpath ${STAGEDIR}${SITE_PERL} \
		-manpath ${STAGEDIR}${PREFIX}/man \
		-batch

.if !defined(NOPORTDOCS)
THEDOCSDIR=	${STAGEDIR}${PREFIX}/share/doc/MHonArc
DOCSDIR=${PREFIX}/share/doc/MHonArc
INSTALL_ARGS+=	-docpath ${THEDOCSDIR}
.else
INSTALL_ARGS+=	-nodoc
.endif

do-install:
	cd ${WRKSRC} && ${PERL5} install.me ${INSTALL_ARGS}

post-install:
.for file in mha-dbedit mha-dbrecover mha-decode mhonarc
	${REINPLACE_CMD} -E -e 's,${STAGEDIR},,g' ${STAGEDIR}/${PREFIX}/bin/${file}
	${RM} ${STAGEDIR}/${PREFIX}/bin/${file}.bak
.endfor

.include <bsd.port.mk>
