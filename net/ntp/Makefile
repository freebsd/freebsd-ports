# New ports collection makefile for:	ntp
# Date created:		Di   5 Mai 1998 21:31:03 CEST
# Whom:			andreas
#
# $FreeBSD$
#

PORTNAME=	ntp
PORTVERSION=	4.0.99i
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.udel.edu/pub/ntp/ntp4/

MAINTAINER=	ports@FreeBSD.org

# ntp's configure script created by autoconf 2.14.1 doesn't work
# if GNU_CONFIGURE is defined
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/ntp
	${TAR} -C ${WRKSRC}/html --exclude '.*' -cf - . | \
		${TAR} -C ${PREFIX}/share/doc/ntp --unlink -xf -
	find ${PREFIX}/share/doc/ntp | xargs ${CHOWN} ${SHAREOWN}:${SHAREGRP}
	find ${PREFIX}/share/doc/ntp -type f | xargs ${CHMOD} ${SHAREMODE}
.endif

.include <bsd.port.mk>
