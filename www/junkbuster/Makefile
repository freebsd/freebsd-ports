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
CATEGORIES=	www
MASTER_SITES=	http://www.junkbusters.com/ht/en/
DISTNAME=	ijb20

MAINTAINER=	ian@broken.net

USE_ZIP=	yes
ALL_TARGET=	# yes, an empty target.
JDIR=		${PREFIX}/etc/junkbuster
MAN1=		junkbuster.1

post-patch:
	@${PERL} -pi -e 's:\r::' ${WRKSRC}/*

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/junkbuster ${PREFIX}/sbin/junkbuster
	${MKDIR} -m 755 ${PREFIX}/etc/junkbuster
	${INSTALL_DATA} ${WRKSRC}/junkbstr.ini ${PREFIX}/etc/junkbuster/configfile.sample
	${INSTALL_DATA} ${WRKSRC}/sblock.ini ${PREFIX}/etc/junkbuster/blockfile.sample
	${INSTALL_DATA} ${WRKSRC}/saclfile.ini ${PREFIX}/etc/junkbuster/aclfile.sample
	${INSTALL_DATA} ${WRKSRC}/scookie.ini ${PREFIX}/etc/junkbuster/cookiefile.sample
	${INSTALL_DATA} ${WRKSRC}/sforward.ini ${PREFIX}/etc/junkbuster/forwardfile.sample
	${INSTALL_DATA} ${WRKSRC}/strust.ini ${PREFIX}/etc/junkbuster/trustfile.sample
	$(INSTALL_MAN) ${WRKSRC}/junkbuster.1 $(PREFIX)/man/man1/
# Create the startup script.  JB will run as user nobody.
	@${SED} -e 's%JDIR%${JDIR}%g' -e 's%PREFIX%${PREFIX}%g' \
	    ${FILESDIR}/junkbuster.sh.in > ${PREFIX}/etc/rc.d/junkbuster.sh
	${CHMOD} 755 ${PREFIX}/etc/rc.d/junkbuster.sh

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
