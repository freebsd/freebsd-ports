# New ports collection makefile for:	loadd
# Date created:		Thu May 2 11:20:06 CET 2002
# Whom:			Alex Dupre <sysadmin@alexdupre.com>
#
# $FreeBSD$
#

PORTNAME=	loadd
PORTVERSION=	0.8
CATEGORIES=	net sysutils
MASTER_SITES=	http://www.bsdshell.net/download/

MAINTAINER=	sysadmin@alexdupre.com

LIB_DEPENDS=	glib12.3:${PORTSDIR}/devel/glib12

USE_REINPLACE=	YES
REINPLACE_ARGS=	#empty

DOCS=		INSTALL LICENSE README TODO
PKGMESSAGE=	${WRKDIR}/pkg-message

MAKE_ENV+=	CPPFLAGS="-DPREFIX=\\\"${PREFIX}\\\""
MAKE_ENV+=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" PTHREAD_LIBS="${PTHREAD_LIBS}"

post-build:
	${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},g' \
		${.CURDIR}/pkg-message.in > ${WRKDIR}/pkg-message

do-install:
	@${ECHO_CMD} "Installing files..."
	@${INSTALL_PROGRAM} ${WRKSRC}/loadd ${PREFIX}/libexec/
	@${INSTALL_SCRIPT} ${FILESDIR}/010.loadd.sh ${PREFIX}/etc/rc.d/
	@${INSTALL_DATA} ${WRKSRC}/loadd.conf ${PREFIX}/etc/loadd.conf.sample
	@${CAT} ${PKGMESSAGE}

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
.for f in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
