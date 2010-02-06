# New ports collection makefile for:	archivesmtp
# Date created:				1 Nov 2009
# Whom:					Netherby <netherby@dancingfortune.com>
#
# $FreeBSD$
#

PORTNAME=	archivesmtp
PORTVERSION=	1.1.b1
CATEGORIES=	mail
MASTER_SITES=	http://www.dancingfortune.com/projects/archivesmtp/files/

MAINTAINER=	contact@dancingfortune.com
COMMENT=	SMTP mail archiver

CFLAGS+=	${PTHREAD_CFLAGS}
LIBS+=		${PTHREAD_LIBS}\
		-lmilter
MAKE_ENV+=	LDADD="${LIBS}"\
		BINDIR="${PREFIX}/sbin"\
		MANDIR="${MANPREFIX}/man/man"\
		NO_MANCOMPRESS="yes"

USE_RC_SUBR=	archivesmtp
SUB_FILES=	pkg-message
SUB_LIST+=	SOCKETBASE=${SOCKETBASE}\
		SOCKETDIR=${SOCKETDIR}
PLIST_SUB+=	${SUB_LIST}

MAN8=		archivesmtp.8

# Path for unix/local socket (by default also used for pid file)
SOCKETBASE?=	/var/run
SOCKETDIR?=	archivesmtp

.include <bsd.port.pre.mk>

# Sets up libmilter dependencies and options
.include "${PORTSDIR}/mail/sendmail/bsd.milter.mk"

pre-build:
	# Copy BSD Makefiles into build tree
	${CP} ${FILESDIR}/top-Makefile ${WRKSRC}/Makefile
	${CP} ${FILESDIR}/src-Makefile ${WRKSRC}/src/Makefile

post-install:
	# Install sample configuration file
	${INSTALL_DATA} ${WRKSRC}/src/archivesmtp.conf.sample ${PREFIX}/etc
	# Create directory for unix/local socket
	${MKDIR} ${SOCKETBASE}/${SOCKETDIR}
	${CHOWN} nobody ${SOCKETBASE}/${SOCKETDIR}
	${CHMOD} 755 ${SOCKETBASE}/${SOCKETDIR}
	# Print post install message
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
