# New ports collection makefile for:	junkbuster
# Date created:		2 May 1998
# Whom:			Ian Struble <ian@broken.net>
#
# $FreeBSD$

# You need to delete the old distfile if you are upgrading, as the tar ball
# for ijb has not been changing names between minor revisions(ie 2.0->2.0.1).
# I have contacted the author about this though so we may see something new
# in the next revision.

PORTNAME=	junkbuster
PORTVERSION=	2.0.2
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://server44.hypermart.net/f2org/ \
		http://f2.org/download/ \
		http://www.junkbusters.com/ht/en/
DISTNAME=	ijb-zlib-10
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	An HTTP proxy server that eliminates ads

USE_REINPLACE=	yes

ALL_TARGET=	# yes, an empty target.
JDIR=		${PREFIX}/etc/junkbuster
MAN1=		junkbuster.1

post-patch:
	@${REINPLACE_CMD} -e "s:`/usr/bin/printf '\r'`::" ${WRKSRC}/*

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/junkbuster ${PREFIX}/sbin/junkbuster
	${MKDIR} -m 755 ${JDIR}
	${INSTALL_DATA} ${WRKSRC}/junkbstr.ini ${JDIR}/configfile.sample
	${INSTALL_DATA} ${WRKSRC}/sblock.ini ${JDIR}/blockfile.sample
	${INSTALL_DATA} ${WRKSRC}/saclfile.ini ${JDIR}/aclfile.sample
	${INSTALL_DATA} ${WRKSRC}/scookie.ini ${JDIR}/cookiefile.sample
	${INSTALL_DATA} ${WRKSRC}/sforward.ini ${JDIR}/forwardfile.sample
	${INSTALL_DATA} ${WRKSRC}/strust.ini ${JDIR}/trustfile.sample
	$(INSTALL_MAN) ${WRKSRC}/junkbuster.1 $(PREFIX)/man/man1/
# Create the startup script.  JB will run as user nobody.
	@${SED} 's|%%JDIR%%|${JDIR}|g ; s|%%PREFIX%%|${PREFIX}|g' \
	    ${FILESDIR}/junkbuster.sh.in > ${WRKDIR}/junkbuster.sh
	${INSTALL_SCRIPT} ${WRKDIR}/junkbuster.sh \
	    ${PREFIX}/etc/rc.d/junkbuster.sh

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
