# New ports collection makefile for:	xenmenu
# Date created:				19 May 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	xenmenu
PORTVERSION=	0.8b
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SUNSITE} \
		http://www.xenos.net/software/xenmenu/
MASTER_SITE_SUBDIR=	apps/misc

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Highly customizable, text-based menu generator
DEPRECATED=	Project abandoned in 1998

ALL_TARGET=	# empty
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-sys-config=${PREFIX}/etc/xenmenurc \
		--with-secure-config=${PREFIX}/etc/xenmenurc.secure \
		--with-support-dir=${PREFIX}/share/xenmenu/bin \
		--with-menu-dir=${PREFIX}/share/xenmenu/menus \
		--with-view-dir=${PREFIX}/share/xenmenu/text \
		--with-path=${PREFIX}/bin:/usr/bin:/bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xenmenu ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/share/xenmenu
	@${MKDIR} ${PREFIX}/share/xenmenu/bin
	@${MKDIR} ${PREFIX}/share/xenmenu/menus
	@${MKDIR} ${PREFIX}/share/xenmenu/text
	@${MKDIR} ${PREFIX}/share/examples/xenmenu/bin
.for file in Makefile README get_backspace.c set_cols.c set_rows.c show_backspace.c show_cols.c show_rows.c
	${INSTALL_DATA} ${WRKSRC}/contrib/${file} ${PREFIX}/share/examples/xenmenu/bin
.endfor
.for file in bbs finger ftp party ssh talk telegram telnet
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/${file} ${PREFIX}/share/examples/xenmenu/bin
.endfor
	@${MKDIR} ${PREFIX}/share/examples/xenmenu/menus
	@${MKDIR} ${PREFIX}/share/examples/xenmenu/menus/games_menus
	@${MKDIR} ${PREFIX}/share/examples/xenmenu/menus/help_menus
.for file in bbs config freeport freeportb freeportc games help helpb internet mail mainmenu other party telmenu telmenu_changecurrent telmenu_changedefault
	${INSTALL_DATA} ${WRKSRC}/sample_menus/${file} ${PREFIX}/share/examples/xenmenu/menus
.endfor
	@${MKDIR} ${PREFIX}/share/examples/xenmenu/menus/bbs_menus
.for file in bbs_menus/technical bbs_menus/general_interest bbs_menus/sig bbs_menus/literary bbs_menus/misc
	${INSTALL_DATA} ${WRKSRC}/sample_menus/${file} ${PREFIX}/share/examples/xenmenu/menus/bbs_menus
.endfor
	@${MKDIR} ${PREFIX}/share/examples/xenmenu/menus/games_menus
.for file in games_menus/multiplayer games_menus/amusements games_menus/singleplayer games_menus/singleplayer2 games_menus/amusements2
	${INSTALL_DATA} ${WRKSRC}/sample_menus/${file} ${PREFIX}/share/examples/xenmenu/menus/games_menus
.endfor
	@${MKDIR} ${PREFIX}/share/examples/xenmenu/menus/help_menus
.for file in help_menus/partyb help_menus/party help_menus/bbs help_menus/bbsb help_menus/mail help_menus/mailb help_menus/abuse help_menus/games help_menus/abuseb help_menus/bbsc help_menus/partyc help_menus/mailc
	${INSTALL_DATA} ${WRKSRC}/sample_menus/${file} ${PREFIX}/share/examples/xenmenu/menus/help_menus
.endfor
	@${MKDIR} ${PREFIX}/share/examples/xenmenu/text
.for file in backspace_help.txt col_help.txt shell_help.txt
	${INSTALL_DATA} ${WRKSRC}/sample_text/${file} ${PREFIX}/share/examples/xenmenu/text
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/xenmenu
.for file in BUGS COPYRIGHT CHANGELOG README README.html TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/xenmenu
.endfor
.endif

.include <bsd.port.mk>
