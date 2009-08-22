# ports collection Makefile for: cone
# Whom:		Matthias Andree <matthias.andree@gmx.de>
# Date created:	2003-06-19
#
# $FreeBSD$
#

PORTNAME=	cone
PORTVERSION=	0.77
CATEGORIES=	mail
# This is for beta versions, leave it in please:
#MASTER_SITES=	http://www.courier-mta.org/beta/${PORTNAME}/ \
#		http://www.lerctr.org/~ler/
# This is for release versions, leave it in please:
MASTER_SITES=	SF/courier/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ler@lerctr.org
COMMENT=	Console based mail client with POP3/IMAP/SMAP support

LIB_DEPENDS=	aspell.16:${PORTSDIR}/textproc/aspell
BUILD_DEPENDS=	gpgv:${PORTSDIR}/security/gnupg1
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_FAM=	yes
USE_GETTEXT=	yes
USE_ICONV=	yes
USE_GNOME=	libxml2

USE_BZIP2=	yes
USE_PERL5=	yes
USE_GMAKE=	yes
CPPFLAGS=	-I${LOCALBASE}/include
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	-C --without-db --with-certdb=${PREFIX}/share/cone/rootcerts --prefix=${PREFIX} --exec-prefix=${PREFIX}

CONFIGURE_ENV=	REHASH="${PERL} ${SCRIPTDIR}/c_rehash" LDFLAGS=-L${LOCALBASE}/lib \
		CPPFLAGS="${CPPFLAGS}"
MAN1=		cone.1 leaf.1 mailtool.1
INSTALL_TARGET=	install-strip

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 700032 || (${OSVERSION} < 700000 && ${OSVERSION} > 602106)
CPPFLAGS+=	-D_XOPEN_SOURCE_EXTENDED
.elif exists(${LOCALBASE}/include/ncurses/ncurses.h) || defined(WITH_NCURSESW)
CPPFLAGS+=	-I${WRKDIR} -D_XOPEN_SOURCE_EXTENDED
LIB_DEPENDS+=	ncursesw.5:${PORTSDIR}/devel/ncurses

post-extract:
		${MKDIR} ${WRKDIR}/ncursesw
		${LN} -s ${LOCALBASE}/include/ncurses/ncurses.h ${WRKDIR}/ncursesw/curses.h
.else

CONFIGURE_ARGS+=	--disable-unicode

pre-everything::
	 @${ECHO_CMD} ""
	 @${ECHO_CMD} "to use multilanguage ( unicode ) MUA, please set WITH_NCURSESW"
	 @${ECHO_CMD} "or install devel/ncurses first"
	 @${ECHO_CMD} ""

.endif

post-install:
		${INSTALL_SCRIPT} ${WRKSRC}/sysconftool ${PREFIX}/sbin/cone-sysconftool
		PKG_PREFIX=${PREFIX} ${SH} pkg-install ${PORTNAME} POST-INSTALL
		${RM} -f ${PREFIX}/share/cone/rootcerts/.0
.if !defined(NOPORTDOCS)
		${MKDIR} ${DOCSDIR}
		${INSTALL_MAN} ${WRKSRC}/ChangeLog ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
