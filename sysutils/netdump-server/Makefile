# New ports collection makefile for:    netdump-server
# Date created:         20 Mar 2005
# Whom:                 Stanislav Sedov
#
# $FreeBSD$

PORTNAME=	netdump-server
PORTVERSION=	0.7.7
PORTREVISION=	1
CATEGORIES=	sysutils net
MASTER_SITES=	http://mbsd.msk.ru/dist/
DISTNAME=	netdump-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	RedHat server part of netdump/netconsole package for linux

LIB_DEPENDS=	popt:${PORTSDIR}/devel/popt \
		glib:${PORTSDIR}/devel/glib20
BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkg-config

PKGMESSAGE=	${WRKDIR}/pkg-message

DOCSFILES=	README README.client
MAN8=		netdump.8 netdump-server.8
NETDUMP_OWN?=	netdump
NETDUMP_GRP?=	operator

USE_RC_SUBR=	netdump-server.sh
PLIST_SUB+=	NETDUMP_OWN=${NETDUMP_OWN} \
		NETDUMP_GRP=${NETDUMP_GRP}
SUB_FILES+=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

PW?=		/usr/sbin/pw

do-install:
	${INSTALL_MAN} ${WRKSRC}/netdump-server.8 ${MANPREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/netdump.8 ${MANPREFIX}/man/man8
	${INSTALL_PROGRAM} ${WRKSRC}/netdump-server ${PREFIX}/bin
	${INSTALL_DATA} ${FILESDIR}/netdump.conf.sample ${PREFIX}/etc
	${MKDIR} ${EXAMPLESDIR}

	for filename in ${WRKSRC}/example_scripts/*; do		\
		${INSTALL_SCRIPT} $${filename} ${EXAMPLESDIR};	\
	done

post-install:

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in ${DOCSFILES}
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.endif

	${PW} groupshow "${NETDUMP_GRP}" 2>/dev/null || \
		${PW} groupadd -n "${NETDUMP_GRP}"
	${PW} usershow "${NETDUMP_OWN}" 2>/dev/null || \
		${PW} useradd -n "${NETDUMP_OWN}" -g "${NETDUMP_GRP}" \
		-s /sbin/nologin -d /nonexistent \
		-c "Netdump-server pseudo user"

	${MKDIR} /var/spool/netdump
	${CHOWN} "${NETDUMP_OWN}:${NETDUMP_GRP}" /var/spool/netdump
	${CHMOD} 700 /var/spool/netdump

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
