# New ports collection makefile for:   slrn
# Date created:        28 March 1997
# Whom:                Carey Jones <mcj@acquiesce.org>
#
# $FreeBSD$
#

PORTNAME=	slrn
PORTVERSION=	0.9.7.4
CATEGORIES=	news ipv6
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		ftp://ftp.rge.com/pub/usenet/readers/unix/slrn/ \
		ftp://angel.sovam.com/pub/tools/net/news/ \
		ftp://ftp.fu-berlin.de/pub/unix/news/slrn/ \
		ftp://ftp.ntua.gr/pub/lang/slang/slrn/ \
		ftp://ftp.plig.org/pub/slrn/
		
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	petef@FreeBSD.org

LIB_DEPENDS=	slang.1:${PORTSDIR}/devel/libslang \
		intl.4:${PORTSDIR}/devel/gettext \
		iconv.3:${PORTSDIR}/converters/libiconv

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-ipv6 --disable-inews --with-slrnpull \
		--with-libiconv-prefix=${LOCALBASE}
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include -L${LOCALBASE}/lib"

.if !defined(WITHOUT_SSL)
USE_OPENSSL=	YES
CONFIGURE_ARGS+=	--with-ssl
.endif

ALL_TARGET=	all

MAN1=		slrn.1 slrnpull.1

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/lib/sendmail,/usr/sbin/sendmail,' \
		${WRKSRC}/src/slrnfeat.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/slrn ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/slrnpull ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/share/examples/slrn
	${INSTALL_DATA} ${WRKSRC}/doc/slrn.rc ${PREFIX}/share/examples/slrn
	(cd ${WRKSRC}/po; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} install)
	@${MKDIR} ${PREFIX}/share/examples/slrn/slrnpull
.for file in FAQ README SETUP score slrn.rc slrnpull.conf slrnpull.sh
	${INSTALL_DATA} ${WRKSRC}/doc/slrnpull/${file} ${PREFIX}/share/examples/slrn/slrnpull
.endfor
	${INSTALL_MAN} ${WRKSRC}/doc/slrn.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/slrnpull.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in FAQ README.* SCORE_FAQ *.txt slrn-doc.html
	${INSTALL_DATA} ${WRKSRC}/doc/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
