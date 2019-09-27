# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pies
PORTVERSION=	1.4
CATEGORIES=	sysutils
MASTER_SITES=	http://download.gnu.org.ua/pub/release/${PORTNAME}/ \
		http://download.gnu.org.ua/pub/alpha/${PORTNAME}/

MAINTAINER=	zeus@gnu.org.ua
COMMENT=	Program Invocation and Execution Supervisor

LICENSE=	GPLv3+

USES=		charsetfix iconv tar:bz2
GNU_CONFIGURE=	yes

INFO=		${PORTNAME}
PORTDOCS=	ChangeLog NEWS README

OPTIONS_DEFINE=	DOCS INETD NLS PAM
OPTIONS_SUB=	yes

INETD_DESC=	Build and install replacement for inetd(8)

INETD_CONFIGURE_ON=	--enable-inetd
NLS_USES=	gettext
NLS_CONFIGURE_OFF=	--disable-nls
PAM_CONFIGURE_OFF=	--disable-pam

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
