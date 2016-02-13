# Created by: Netherby <netherby@dancingfortune.com>
# $FreeBSD$

PORTNAME=	archivesmtp
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.dancingfortune.com/projects/archivesmtp/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SMTP mail archiver

LIBS+=		-lmilter -lpthread
MAKE_ENV+=	LDADD="${LIBS}"

USE_RC_SUBR=	archivesmtp
SUB_FILES=	pkg-message
SUB_LIST+=	SOCKETBASE="${SOCKETBASE}"\
		SOCKETDIR="${SOCKETDIR}"
PLIST_SUB+=	${SUB_LIST}

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

do-install:
	${INSTALL} -s ${WRKSRC}/src/archivesmtp ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/src/archivesmtp.8 ${STAGEDIR}${PREFIX}/man/man8

post-install:
	# Install sample configuration file
	${INSTALL_DATA} ${WRKSRC}/src/archivesmtp.conf.sample ${STAGEDIR}${PREFIX}/etc
	# Create socket directory
	@${MKDIR} ${STAGEDIR}${SOCKETBASE}/${SOCKETDIR}

.include <bsd.port.post.mk>
