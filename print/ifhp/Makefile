# Ports collection makefile for:	ifhp
# Date created:		10 Oct 2001
# Whom:			papowell@astart.com
#
# $FreeBSD$
#

PORTNAME=	ifhp
PORTVERSION=	3.5.20
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.lprng.com/pub/%SUBDIR%/ \
		ftp://ftp.cise.ufl.edu/pub/mirrors/%SUBDIR%/ \
		ftp://ftp.cs.umn.edu/pub/%SUBDIR%/ \
		ftp://ftp.informatik.uni-hamburg.de/pub/os/unix/utils/%SUBDIR%/ \
		ftp://ftp.uni-paderborn.de/pub/unix/printer/%SUBDIR%/
MASTER_SITE_SUBDIR=	LPRng/ifhp
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	IFHP - A highly configurable print filter for LPRng

BROKEN=		Size mismatch

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GHOSTSCRIPT=	yes
WANT_PERL=	yes

MAN8=		ifhp.8 textps.8

SUB_FILES=	pkg-message
SUB_LIST=	DOCSDIR=${DOCSDIR}

CONFIGURE_ENV=	LDFLAGS="${LDFLAGS} -L{LOCALBASE}/lib" \
		CFLAGS="${CFLAGS} -I${LOCALBASE}/include"
.if defined(PREFIX)
CONFIGURE_ARGS+=	--prefix="${PREFIX}"
.endif
.if defined(SYSCONFDIR)
CONFIGURE_ARGS+=	--sysconfdir="${SYSCONFDIR}"
.endif

OPTIONS=	FOOMATIC	"Enable foomatic support"	on \
		SNMP		"Enable SNMP support"		on

.if !defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--enable-nls --with-libiconv-prefix=${LOCALBASE} \
			--with-libintl-prefix=${LOCALBASE}
USE_GETTEXT=		yes
PLIST_SUB+=		NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=		NLS="@comment "
.endif

.include <bsd.port.pre.mk>

.if defined(WITHOUT_FOOMATIC)
CONFIGURE_ARGS+=	--disable-foomatic
.else
BUILD_DEPENDS+=		foomatic-rip:${PORTSDIR}/print/foomatic-filters
.endif

.if defined(WITHOUT_SNMP)
CONFIGURE_ARGS+=	--disable-snmp
.else
BUILD_DEPENDS+=		${SITE_PERL}/Net/SNMP.pm:${PORTSDIR}/net-mgmt/p5-Net-SNMP
.endif

pre-everything::
	@${ECHO_MSG} "If you want to replace the default printing system with LPRng, use:"
	@${ECHO_MSG} "  make PREFIX=/usr SYSCONFDIR=/etc clean all install"
	@if [ "${PREFIX}" = "/usr" -a ! -d /usr/man ] ; then \
		${ECHO_MSG} "The man pages will be installed in /usr/man." ; \
		${ECHO_MSG} "You should make a symbolic link /usr/share/man from /usr/man"; \
		${ECHO_MSG} "   ln -s /usr/share/man /usr/man"; \
		${ECHO_MSG} "If you do not, you will retain the old FreeBSD man pages."; \
		${ECHO_MSG} "See the hier(7) man page for details of the FreeBSD file system"; \
		${ECHO_MSG} "layout.  Configure is not equipped to determine the location of"; \
		${ECHO_MSG} 'man pages and defaults to $${PREFIX}/man, which is incorrect for FreeBSD.'; \
	fi
	@${ECHO_MSG} "Configuring with '${CONFIGURE_ARGS}'"

post-patch:
	@${REINPLACE_CMD} -e 's|-Werror||' ${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	@${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} -m 0555 ${DOCSDIR}
.for ext in html pdf ppt ps txt gif jpg png
	@for i in `${LS} ${WRKSRC}/DOCS |${GREP} "\.${ext}$$"`; \
		do ${INSTALL_DATA} ${WRKSRC}/DOCS/$$i ${DOCSDIR}; done
.endfor
.endif

.include <bsd.port.post.mk>
