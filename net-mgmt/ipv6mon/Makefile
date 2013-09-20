# Created by: Hiroki Sato <hrs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ipv6mon
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	net-mgmt ipv6
MASTER_SITES=	http://www.si6networks.com/tools/ipv6mon/
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Tool for monitoring IPv6 address usage

LICENSE=	GPLv3

MAKE_ENV=	DESTDIR=${PREFIX}/
CFLAGS+=	-DIPV6MON_CONF=\\\"${PREFIX}/etc/ipv6mon.conf\\\"
USERS=		${PORTNAME}
GROUPS=		${PORTNAME}
USE_RC_SUBR=	${PORTNAME}

MAN5=		ipv6mon.conf.5
MAN8=		ipv6mon.8

PORTDOCS=	README.TXT \
		ipv6mon-installation-notes.odt \
		ipv6mon-installation-notes.pdf \
		ipv6mon-manual.odt \
		ipv6mon-manual.pdf

NO_STAGE=	yes
post-extract:
	${INSTALL_DATA} ${WRKSRC}/manuals/* ${WRKSRC}

post-install:
	if [ ! -r ${PREFIX}/etc/ipv6mon.conf ]; then \
		${INSTALL_DATA} ${PREFIX}/etc/ipv6mon.conf.dist \
			${PREFIX}/etc/ipv6mon.conf; \
	fi
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/etc/rc.d
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && \
		${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
