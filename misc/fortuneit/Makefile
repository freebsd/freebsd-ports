# Created by: gmarco@giovannelli.it
# $FreeBSD$

PORTNAME=	fortuneit
PORTVERSION=	1.99
CATEGORIES=	misc
MASTER_SITES=	http://utenti.gufi.org/~gmarco/files/distfiles/
DISTNAME=	fortune-it-${PORTVERSION}

MAINTAINER=	gmarco@gufi.org
COMMENT=	Funny fortune file in Italian

STRCMD=		/usr/games/strfile

FORTUNEFILES=	adams banner computer definizioni formiche italia itatrek \
		jackfr leggi luke luttazzi norm paolotedeschi zuse \
		computer-o definizioni-o film-o italia-o jackfr-o leggi-o \
		luttazzi-o obsc-o zuse-o

NO_STAGE=	yes
pre-build:
.if !exists(${STRCMD})
	@${ECHO_MSG} "Please install the games distribution"
	@exit 1
.endif

do-build:
.for f in ${FORTUNEFILES}
	${STRCMD} ${WRKSRC}/testi/${f}
.endfor

do-install:
	@${MKDIR} ${PREFIX}/share/games
	@${MKDIR} ${PREFIX}/share/games/fortune
.for f in ${FORTUNEFILES}
	@${INSTALL_DATA} ${WRKSRC}/testi/${f}* ${PREFIX}/share/games/fortune
.endfor

post-install:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Usage:"
	@${ECHO_MSG} "/usr/games/fortune [-aDefilosw] ${PREFIX}/share/games/fortune/"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Please check fortune manual pages for more informations"
	@${ECHO_MSG} ""

.include <bsd.port.mk>
