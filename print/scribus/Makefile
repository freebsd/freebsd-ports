# ex:ts=8
# Ports collection makefile for:	scribus
# Date created:			Mar 15, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=		scribus
PORTVERSION=		0.8
PORTREVISION=		1
CATEGORIES=		print editors
MASTER_SITES=		http://web2.altmuehlnet.de/fschmid/
DIST_SUBDIR=		${PORTNAME}
PATCH_SITES=		${MASTER_SITES}
PATCHFILES=		Fonts.diff Palette.diff
PATCH_DIST_STRIP=	-p1

MAINTAINER=		alane@freebsd.org

RUN_DEPENDS+=		gs:${PORTSDIR}/print/ghostscript-gnu

USE_QT_VER=		3
USE_REINPLACE=		yes
GNU_CONFIGURE=		yes

INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	%%PREFIX%%/share/scribus/libs \
		%%PREFIX%%/share/scribus/plugins

BROKEN=	"This program terminates with a SIGBUS or simply hangs"

post-patch::
	${FIND} ${WRKSRC} -type f			\
		|${XARGS} ${GREP} -l 'share/scribus/doc'\
		|${XARGS} -n 1 ${REINPLACE_CMD} \
			-e 's|share/scribus/doc|share/doc/scribus|'

.if defined(NOPORTDOCS)
post-patch::
	${REINPLACE_CMD} -e "s|docs icons|icons|" \
		${WRKSRC}/scribus/Makefile.in
.endif # defined(NOPORTDOCS)

post-configure::
	${FIND} ${WRKSRC} -name Makefile	\
		|${XARGS} -n 1 ${REINPLACE_CMD} -e 's|-O2||g'

.include <bsd.port.mk>
