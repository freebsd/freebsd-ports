# New ports collection makefile for:	dropbear
# Date created:				20 August 2003
# Whom:					Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$
#

PORTNAME=	dropbear
PORTVERSION=	0.50
CATEGORIES=	security ipv6
MASTER_SITES=	http://matt.ucc.asn.au/dropbear/releases/

MAINTAINER=	spam@rm-rf.kiev.ua
COMMENT=	An SSH 2 server, designed to be usable in small memory environments

GNU_CONFIGURE=	YES
USE_GMAKE=	YES

OPTIONS=	STATIC  "Build statically"  off

USE_RC_SUBR=	${PORTNAME}

.include <bsd.port.pre.mk>

.if defined(WITH_STATIC)
CONFIGURE_ENV=	LDFLAGS=-static
.endif

post-patch:
	@${REINPLACE_CMD} -e "s,_PRIV_FILENAME \"/etc/,_PRIV_FILENAME \"${PREFIX}/etc/,g; \
		s,/usr/bin/X11/,${X11BASE}/,g" ${WRKSRC}/options.h
	@${REINPLACE_CMD} -e "s,sys/dir.h,dirent.h," ${WRKSRC}/*.[ch]
	@${REINPLACE_CMD} -e "s,make clean,\$${MAKE} clean," \
				${WRKSRC}/libtomcrypt/Makefile.in

post-install:
	@${MKDIR} ${PREFIX}/etc/dropbear
	@${ECHO_MSG} ""

.include <bsd.port.post.mk>
