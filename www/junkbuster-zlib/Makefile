# New ports collection makefile for:	junkbuster-zlib
# Date created:		2 May 1998
# Whom:			Ian Struble <ian@broken.net>
#
# $FreeBSD$
#

PORTNAME=	junkbuster-zlib
PORTVERSION=	1.0
CATEGORIES=	www
MASTER_SITES=	http://server44.hypermart.net/f2org/ \
		http://f2.org/download/
DISTNAME=	ijb-zlib-${PORTVERSION:S/.//g}
EXTRACT_SUFX=	.tgz

MAINTAINER=	sobomax@FreeBSD.org

ALL_TARGET=	# yes, an empty target.
JDIR=		${PREFIX}/etc/junkbuster-zlib
MAN1=		junkbuster-zlib.1

post-patch:
	@${PERL} -pi -e 's:\r::' ${WRKSRC}/*

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/junkbuster ${PREFIX}/sbin/junkbuster-zlib
	${MKDIR} -m 755 ${JDIR}
	${INSTALL_DATA} ${WRKSRC}/junkbstr.ini ${JDIR}/configfile.sample
	${INSTALL_DATA} ${WRKSRC}/sblock.ini ${JDIR}/blockfile.sample
	${INSTALL_DATA} ${WRKSRC}/saclfile.ini ${JDIR}/aclfile.sample
	${INSTALL_DATA} ${WRKSRC}/scookie.ini ${JDIR}/cookiefile.sample
	${INSTALL_DATA} ${WRKSRC}/sforward.ini ${JDIR}/forwardfile.sample
	${INSTALL_DATA} ${WRKSRC}/strust.ini ${JDIR}/trustfile.sample
	$(INSTALL_MAN) ${WRKSRC}/junkbuster.1 $(PREFIX)/man/man1/junkbuster-zlib.1
# Create the startup script.  JB will run as user nobody.
	@${SED} 's|%%JDIR%%|${JDIR}|g ; s|%%PREFIX%%|${PREFIX}|g' \
	    ${FILESDIR}/junkbuster.sh.in > ${WRKDIR}/junkbuster-zlib.sh
	${INSTALL_SCRIPT} ${WRKDIR}/junkbuster-zlib.sh \
	    ${PREFIX}/etc/rc.d/junkbuster-zlib.sh

post-install:
	@${SED} 's|%%PREFIX%%|${PREFIX}|g' ${PKGMESSAGE}

.include <bsd.port.mk>
