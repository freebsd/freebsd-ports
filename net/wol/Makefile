# Created by: ijliao
# $FreeBSD$

PORTNAME=	wol
PORTVERSION=	0.7.1
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	SF/ahh/OldFiles

MAINTAINER=	david@catwhisker.org
COMMENT=	Tool to wake up Wake-On-LAN compliant computers

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		localbase perl5
GNU_CONFIGURE=	yes
USE_PERL5=	build

INFO=		wol
DOCS=		AUTHORS NEWS README TODO

OPTIONS_DEFINE=	DOCS NLS

OPTIONS_SUB=	yes
NLS_USES=	gettext iconv
NLS_CONFIGURE_OFF=	--disable-nls

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
