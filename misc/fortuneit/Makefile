# Created by: gmarco@giovannelli.it
# $FreeBSD$

PORTNAME=	fortuneit
PORTVERSION=	1.99
CATEGORIES=	misc
MASTER_SITES=	http://utenti.gufi.org/~gmarco/files/distfiles/
DISTNAME=	fortune-it-${PORTVERSION}

MAINTAINER=	gmarco@gufi.org
COMMENT=	Funny fortune file in Italian

BUILD_DEPENDS=	fortune_strfile:misc/fortune_strfile
STRCMD=		${LOCALBASE}/bin/fortune_strfile

FORTUNEFILES=	adams banner computer definizioni formiche italia itatrek \
		jackfr leggi luke luttazzi norm paolotedeschi zuse \
		computer-o definizioni-o film-o italia-o jackfr-o leggi-o \
		luttazzi-o obsc-o zuse-o

do-build:
.for f in ${FORTUNEFILES}
	${STRCMD} ${WRKSRC}/testi/${f}
.endfor

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/games/fortune
.for f in ${FORTUNEFILES}
	${INSTALL_DATA} ${WRKSRC}/testi/${f}* \
		${STAGEDIR}${PREFIX}/share/games/fortune
.endfor

.include <bsd.port.mk>
