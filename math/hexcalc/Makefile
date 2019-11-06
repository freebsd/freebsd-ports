# Created by: jhs@berklix.com / asami (original)
# $FreeBSD$

PORTNAME=	hexcalc
PORTVERSION=	1.11
PORTREVISION=	3
CATEGORIES=	math
MASTER_SITES=	http://www.berklix.com/~jhs/ftp/FreeBSD/ports/distfiles/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	jhs@berklix.com
COMMENT=	Multi-radix calculator for x11

# XORG_CAT=	app
# USES= imake
#	Maybe later.
#	It would move from distfiles/hexcalc..tar.Z
#	to distfiles/xorg/app/hexcalc..tar.Z & require change in distinfo

#	Old distfile name in 8.2 was hexcalc..tar.Z & EXTRACT_SUFX was ..tar.Z
#	presumably a mistake, now shortened to normality.

USES=		xorg
USE_XORG=	ice sm x11 xaw xext xmu xt

PLIST_FILES=	bin/hexcalc man/man1/hexcalc.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hexcalc ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/hexcalc.man \
		${STAGEDIR}${MANPREFIX}/man/man1/hexcalc.1
	@# The manual installed OK on 9.1-RELEASE without do-install,
	@# but manual install failed on 9.2-RELEASE & 10.0-RELEASE,
	@# so I added do-install, which does no harm on 9.1 & 9.2.
	@# Maybe do-install can be discarded if MAN variables are set right ?

.include <bsd.port.mk>
