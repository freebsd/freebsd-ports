# New ports collection makefile for:	Eric Young's SSL/Crypto Library
# Version required:	0.9.0b
# Date created:		15 Aug 1997
# Whom:			markm@freebsd.org
#
# $Id: Makefile,v 1.22 1998/10/26 05:52:02 obrien Exp $
#

DISTNAME=		SSLeay-0.9.0b
CATEGORIES=		devel security
MASTER_SITES=		ftp://psych.psy.uq.oz.au/pub/Crypto/SSL/  \
			ftp://ftp.funet.fi/pub/mirrors/ftp.psy.uq.oz.au/SSL/  \
			ftp://sunsite.doc.ic.ac.uk/Mirrors/ftp.psy.uq.oz.au/pub/Crypto/SSL/  \
 			ftp://ftp.internat.freebsd.org/pub/Crypto/SSL/


MAINTAINER=		markm@FreeBSD.ORG

BROKEN=			upgrade

RESTRICTED=		"Cryptography"
HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	util/FreeBSD.sh

.if !defined(USA_RESIDENT) || ${USA_RESIDENT} != YES && ${USA_RESIDENT} != NO
pre-fetch:
	@echo
	@echo You must set variable USA_RESIDENT to YES, if you are USA resident
	@echo or to NO, if you aren\'t USA resident to build this package.
	@echo You must also have installed RSAREF if you are USA resident.
	@false
.elif defined(USA_RESIDENT)
.if ${USA_RESIDENT} == YES
LIB_DEPENDS=		rsaref.2:${PORTSDIR}/security/rsaref

post-configure:
	${CP} ${WRKSRC}/rsaref/rsaref.h ${WRKSRC}/include/rsaref.h
	(${PATCH} <${FILESDIR}/Makefile.patch)
.endif
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/SSLeay
	@${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/doc/SSLeay
.endif

.include <bsd.port.mk>
