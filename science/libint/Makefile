# New ports collection makefile for:	libint
# Date created:				29 Dec 2006
# Whom:					NAKATA, Maho <maho@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libint
PORTVERSION=	1.1.2
PORTREVISION=	1
CATEGORIES=	science
MASTER_SITES=	http://www.chem.vt.edu/chem-dept/valeev/software/libint/src/

MAINTAINER=	maho@FreeBSD.org
COMMENT=	Evaluate the integrals in modern atomic and molecular theory

USE_PERL5=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
ALL_TARGET=	# empty

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared

post-patch:
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|' ${WRKSRC}/configure

post-install:
	@${LN} -sf ${PREFIX}/lib/libderiv-stable.so.1 ${PREFIX}/lib/libderiv.so.1
	@${LN} -sf ${PREFIX}/lib/libint-stable.so.1 ${PREFIX}/lib/libint.so.1
	@${LN} -sf ${PREFIX}/lib/libr12-stable.so.1 ${PREFIX}/lib/libr12.so.1

.include <bsd.port.mk>
