# New ports collection makefile for:	irssi-themes
# Date created:				17 Sep 2006
# Whom:					Emanuel Haupt <ehaupt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	irssi-themes
PORTVERSION=	20060917
CATEGORIES=	x11-themes irc
MASTER_SITES=	http://www.irssi.org/themefiles/ \
		http://critical.ch/distfiles/${PORTNAME}/ \
		http://energy.critical.ch/distfiles/${PORTNAME}/
DISTFILES=	BitchX.theme IamCyan.theme agon.theme ash.theme asyura.theme \
		bestican.theme bluu.theme bork.theme c0ders.theme \
		cananal.theme chaves.theme chill.theme clean.theme crap.theme \
		cross.theme cyanic.theme darksystem.theme daywalker.theme  \
		defacto.theme ea1.theme easyeye.theme ectobar.theme ekh.theme \
		en.theme eon.theme epic.theme evilkat.theme evolution.theme \
		fluxmod.theme foo.theme foxmask.theme garden.theme \
		generane.theme gothic.theme green.theme greenSCPleo.theme \
		greenish.theme hagge.theme hellfire.theme hnsk.theme \
		huara.theme hv.theme industrial.theme ion.theme ion_mod.theme \
		jokx.theme jsuvanto.theme kaer-2.theme kaer.theme \
		koivula.theme kompakt.theme ksiadz.theme kurja.theme \
		laaama-2.theme laaama.theme lemac-pl.theme lemac.theme \
		lemmu.theme lesscolors.theme lilah.theme lime.theme litE.theme \
		liten.theme lyynx.theme madcow.theme madeye.theme magick.theme \
		mazii.theme mika.theme mine.theme mirkk32.theme misso.theme \
		mrooveq.theme mutru.theme naula.theme neutralorange.theme \
		nigga.theme ocean.theme osbxwannabe.theme oxynox.theme \
		pasce.theme pgreen.theme pikkuh.theme qlth.theme quubba.theme \
		quux.theme relaxed.theme rettoscopia.theme roses.theme \
		salsa.theme screwer.theme sfc1337.theme sfcblue.theme \
		shrike.theme shruuf.theme simple.theme simpleii.theme \
		skan.theme skeita.theme ski.theme splitfire.theme spot.theme \
		sputnik.theme stevee.theme stx.theme sux.theme swift.theme \
		tanke.theme telix.theme thirdeye.theme tinylajs.theme \
		trax.theme void.theme vt510+xterm.theme white.theme \
		whitespace.theme xmas.theme zhafte.theme zng.theme
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	A collection of additional irssi themes

RUN_DEPENDS=	irssi:${PORTSDIR}/irc/irssi

NO_BUILD=	yes

do-extract:
	@${MKDIR} ${WRKSRC}
.for f in ${DISTFILES}
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${f} ${WRKSRC}
.endfor

do-install:
.for f in ${DISTFILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/irssi/themes/
.endfor

.include <bsd.port.mk>
