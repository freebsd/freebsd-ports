# Created by: Hiroki Sato <hrs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ipv6mon
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	net-mgmt ipv6
MASTER_SITES=	http://www.si6networks.com/tools/ipv6mon/
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Tool for monitoring IPv6 address usage

OPTIONS_DEFINE=	DOCS

LICENSE=	GPLv3

USES=		uidfix
#Ignore "normal" destdir from port infra
DESTDIRNAME=	IGNOREME
MAKE_ENV=	DESTDIR=${STAGEDIR}${PREFIX}/
CFLAGS+=	-DIPV6MON_CONF=\\\"${PREFIX}/etc/ipv6mon.conf\\\"
USERS=		${PORTNAME}
GROUPS=		${PORTNAME}
USE_RC_SUBR=	${PORTNAME}

PORTDOCS=	README.TXT \
		ipv6mon-installation-notes.odt \
		ipv6mon-installation-notes.pdf \
		ipv6mon-manual.odt \
		ipv6mon-manual.pdf

post-extract:
	${INSTALL_DATA} ${WRKSRC}/manuals/* ${WRKSRC}

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/etc/rc.d
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && \
		${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
