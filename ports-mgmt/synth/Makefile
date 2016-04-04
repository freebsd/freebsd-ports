# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	synth
PORTVERSION=	1.33
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	ports-mgmt

MAINTAINER=	marino@FreeBSD.org
COMMENT=	Custom package repository builder for FreeBSD and DragonFly

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/License.txt

#BUILD_DEPENDS=	${LOCALBASE}/lib/gnat/${IFM}.gpr:misc/${IFM} \
#		${LOCALBASE}/lib/gnat/${AC}.gpr:devel/${AC}

USES=		ada:6 ncurses:port
USE_GITHUB=	yes
GH_ACCOUNT=	jrmarino
GH_PROJECT=	synth_external:bundle
GH_TAGNAME=	v1.3:bundle

# When framework is moved to Ada6, the ada-util and ini-file-manager
# libraries can be used as prebuilt (switch default.gpr url)
# ncurses:port is required for FreeBSD 11 and DragonFly (base ncurses
# malfunctions in that it won't restore TTY mode correctly)

COBJFILES=	ncurses_compat.o c_varargs_to_ada.o c_threaded_variables.o

post-extract:
	@${MV} ${WRKSRC_bundle}/external ${WRKSRC}
	@${REINPLACE_CMD} -e "s|/usr/local|${LOCALBASE}|" \
		${WRKSRC}/external/lib/gnat/adacurses.gpr \
		${WRKSRC}/src/definitions.ads

do-build:
	# To avoid requiring gprbuild as a dependency, compile C manually
.for csrc in ${COBJFILES:R}
	(cd ${WRKSRC}/external/include/adacurses && \
		${SETENV} ${MAKE_ENV} gcc -I. ${CFLAGS} -c ${csrc}.c \
		-o ../../build/adacurses/${csrc}.o)
.endfor
	(cd ${WRKSRC}/src && ${SETENV} ${MAKE_ENV} \
		gcc -c unix_core.c -o ../build/unix_core.o)
	(cd ${WRKSRC}/synthexec && ${SETENV} ${MAKE_ENV} \
		gcc synthexec.c -o ../build/synthexec)
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} gnatmake -P default \
		-largs build/unix_core.o)

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions \
		${STAGEDIR}/var/log/synth \
		${STAGEDIR}/var/synth/live_packages
	${INSTALL_PROGRAM} ${WRKSRC}/build/synth \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/build/synthexec \
		${STAGEDIR}${PREFIX}/libexec
	${INSTALL_MAN} ${WRKSRC}/synth.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_SCRIPT} ${WRKSRC}/shell-completers/_synth.bash \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/shell-completers/_synth \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions

.include <bsd.port.mk>
