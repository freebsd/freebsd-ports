PORTNAME=	mhonarc
PORTVERSION=	2.6.24
CATEGORIES=	www mail

MAINTAINER=	kerndtr@kerndt.com
COMMENT=	WWW front end for mail archives

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe tar:bzip2 perl5
USE_GITHUB=	YES
GH_ACCOUNT=	sympa-community
GH_PROJECT=	MHonArc

NO_BUILD=	yes
NO_ARCH=	yes

INSTALL_ARGS=	-prefix ${STAGEDIR} -binpath ${STAGEDIR}${PREFIX}/bin \
		-libpath ${STAGEDIR}${PREFIX}/${SITE_PERL_REL} \
		-manpath ${STAGEDIR}${PREFIX}/man \
		-batch

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
THEDOCSDIR=	${STAGEDIR}${PREFIX}/share/doc/MHonArc
DOCSDIR=${PREFIX}/share/doc/MHonArc
INSTALL_ARGS+=	-docpath ${THEDOCSDIR}
.else
INSTALL_ARGS+=	-nodoc
.endif

do-install:
	cd ${WRKSRC} && ${PERL5} install.me ${INSTALL_ARGS}

.for file in mha-dbedit mha-dbrecover mha-decode mhonarc
	${REINPLACE_CMD} -E -e 's,${STAGEDIR},,g' ${STAGEDIR}/${PREFIX}/bin/${file}
	${RM} ${STAGEDIR}/${PREFIX}/bin/${file}.bak
.endfor

.include <bsd.port.mk>
