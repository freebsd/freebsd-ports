# Created by: NAKATA, Maho <maho@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libint
PORTVERSION=	1.1.4
PORTREVISION=	1
CATEGORIES=	science
MASTER_SITES=	http://www.files.chem.vt.edu/chem-dept/valeev/software/libint/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Evaluate the integrals in modern atomic and molecular theory

USES=		perl5 gmake libtool
USE_LDCONFIG=	yes
ALL_TARGET=	# empty

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared

post-patch:
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|' ${WRKSRC}/configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so

.include <bsd.port.mk>
