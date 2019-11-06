# $FreeBSD$

PORTNAME=	ipv6mon
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.si6networks.com/tools/ipv6mon/
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Tool for monitoring IPv6 address usage

BROKEN=		unfetchable

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT

USES=		uidfix
CFLAGS+=	-DIPV6MON_CONF=\\\"${PREFIX}/etc/ipv6mon.conf\\\"
USERS=		${PORTNAME}
GROUPS=		${PORTNAME}
USE_RC_SUBR=	${PORTNAME}

PORTDOCS=	README.TXT \
		ipv6mon-installation-notes.odt \
		ipv6mon-installation-notes.pdf \
		ipv6mon-manual.odt \
		ipv6mon-manual.pdf

OPTIONS_DEFINE=	DOCS

post-extract:
	@${INSTALL_DATA} ${FILESDIR}/Makefile ${WRKSRC}
	@${INSTALL_DATA} ${WRKSRC}/manuals/* ${WRKSRC}

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/etc/rc.d

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && \
		${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
