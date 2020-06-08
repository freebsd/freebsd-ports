# $FreeBSD$

PORTNAME=	ipv6mon
PORTVERSION=	1.0
PORTREVISION=	4
CATEGORIES=	net-mgmt

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Tool for monitoring IPv6 address usage

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT

USES=		uidfix
GH_ACCOUNT=	fgont
GH_PROJECT=	ipv6mon
GH_TAGNAME=	454292a393ddd79db7131b6e7a8d005a7f49bd92
USE_GCC=	any
USE_GITHUB=	nodefault
CFLAGS+=	-DIPV6MON_CONF=\\\"${PREFIX}/etc/ipv6mon.conf\\\"
USERS=		${PORTNAME}
GROUPS=		${PORTNAME}
USE_RC_SUBR=	${PORTNAME}

PORTDOCS=	README.TXT \
		ipv6mon-installation-notes.odt \
		ipv6mon-installation-notes.pdf \
		ipv6mon-manual.odt \
		ipv6mon-manual.pdf
WRKSRC=		${WRKDIR}/${GH_PROJECT}-${GH_TAGNAME}

OPTIONS_DEFINE=	DOCS

post-extract:
	${INSTALL_DATA} ${FILESDIR}/Makefile ${WRKSRC}
	${INSTALL_DATA} ${WRKSRC}/manuals/* ${WRKSRC}
	@${REINPLACE_CMD} 's|/etc/|${PREFIX}/etc/|'\
		${WRKSRC}/ipv6mon.8 ${WRKSRC}/ipv6mon.conf.5

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/etc/rc.d

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && \
		${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
