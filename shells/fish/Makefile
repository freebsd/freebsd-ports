# New ports collection makefile for:	fish
# Date created:		2007-02-26
# Whom:			Kai Wang <kaiw27@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	fish
PORTVERSION=	1.22.3
PORTREVISION=	4
CATEGORIES=	shells
MASTER_SITES=	http://www.fishshell.org/files/1.22.3/ \
		http://roo.no-ip.org/fish/files/1.22.3/ \
		http://web.student.chalmers.se/~kaiw/FreeBSD/disfiles/

MAINTAINER=	kaiw27@gmail.com
COMMENT=	A user friendly command line shell

USE_AUTOTOOLS=	autoconf:262
USE_ICONV=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LIBS="${LDFLAGS}" \
		LDFLAGS="${LDFLAGS}"

OPTIONS=	NLS	"Native language support"	on \
		XSEL	"Build with xsel"		on

MAN1=		count.1 fish.1 fish_pager.1 fishd.1 \
		mimedb.1 set_color.1 alias.1 and.1 begin.1 \
		bg.1 bind.1 block.1 break.1 builtin.1 \
		case.1 cd.1 command.1 commandline.1 complete.1 \
		contains.1 continue.1 dirh.1 dirs.1 else.1 \
		end.1 eval.1 exec.1 exit.1 fg.1 for.1 \
		function.1 functions.1 help.1 if.1 isatty.1 \
		jobs.1 math.1 nextd.1 not.1 open.1 or.1 \
		popd.1 prevd.1 psub.1 pushd.1 random.1 \
		read.1 return.1 save_function.1 set.1 \
		source.1 status.1 switch.1 trap.1 type.1 \
		ulimit.1 umask.1 vared.1 while.1

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_NLS)
USE_GETTEXT=		yes
PLIST_SUB+=		NLS=""
.else
CONFIGURE_ARGS+=	--without-gettext
PLIST_SUB+=		NLS="@comment "
.endif

.if !defined(WITHOUT_XSEL)
CONFLICTS=		xsel-[0-9]*
PLIST_SUB+=		XSEL=""
MAN1+=			xsel.1
.else
CONFIGURE_ARGS+=	--without-xsel
PLIST_SUB+=		XSEL="@comment "
.endif

post-install:
.if !defined(WITHOUT_XSEL)
	${MV} ${PREFIX}/man/man1/xsel.1x ${PREFIX}/man/man1/xsel.1
.endif
# remove duplicate manpages
.for i in count.1 fish.1 fish_pager.1 fishd.1 mimedb.1 set_color.1
	cd ${DATADIR}/man && ${RM} -f ${i}
.endfor
	${CP} ${DATADIR}/man/*.1 ${PREFIX}/man/man1/
	${RM} -rf ${DATADIR}/man
	if ${GREP} -q '${PREFIX}/bin/${PORTNAME}' /etc/shells; then \
		${TRUE}; \
	else \
		${ECHO_CMD} '${PREFIX}/bin/${PORTNAME}' >> /etc/shells; \
	fi

post-deinstall:
	${CP} /etc/shells /etc/shells.bak
	${GREP} -v '${PREFIX}/bin/${PORTNAME}' /etc/shells.bak \
		>> /etc/shells
	${RM} -f /etc/shells.bak

.include <bsd.port.post.mk>
