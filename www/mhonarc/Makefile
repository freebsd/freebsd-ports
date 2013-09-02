# New ports collection makefile for:	MHonArc
# Date created:				18 June 1997
# Whom:					koshy@india.hp.com
#
# $FreeBSD$
#

PORTNAME=	mhonarc
PORTVERSION=	2.6.18
PORTREVISION=	1
CATEGORIES=	www mail
MASTER_SITES=	http://www.mhonarc.org/release/MHonArc/tar/ \
		http://www.oac.uci.edu/indiv/ehood/tar/
DISTNAME=	MHonArc-${PORTVERSION}

MAINTAINER=	kerndtr@kerndt.com
COMMENT=	WWW front end for mail archives

USE_BZIP2=	Yes
USES=		perl5
NO_BUILD=	Yes

MAN1=	mhonarc.1 mha-dbedit.1 mha-dbrecover.1 mha-decode.1

INSTALL_ARGS=	-binpath ${PREFIX}/bin \
		-libpath ${SITE_PERL} \
		-manpath ${PREFIX}/man \
		-batch

.if !defined(NOPORTDOCS)
DOCSDIR=	${PREFIX}/share/doc/MHonArc
INSTALL_ARGS+=	-docpath ${DOCSDIR}
.else
INSTALL_ARGS+=	-nodoc
.endif

do-install:
	cd ${WRKSRC} && ${PERL5} install.me ${INSTALL_ARGS}

.include <bsd.port.mk>
