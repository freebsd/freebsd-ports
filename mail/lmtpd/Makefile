# New ports collection makefile for:	libhome
# Date created:				Fri Aug 14 2003
# Whom:					Xavier Beaudouin <kiwi@oav.net>
#
# $FreeBSD$
#

PORTNAME=	lmtpd
PORTVERSION=	0.9.13
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pll

MAINTAINER=	kiwi@oav.net
COMMENT=	LMTP server compliant with RFC 2033 and Maildir++

LIB_DEPENDS=	mysqlclient:${PORTSDIR}/databases/mysql323-client \
		pcre:${PORTSDIR}/devel/pcre \
		iconv:${PORTSDIR}/converters/libiconv \
		db3.3:${PORTSDIR}/databases/db3
BUILD_DEPENDS=	${LOCALBASE}/lib/libhome.a:${PORTSDIR}/misc/libhome

GNU_CONFIGURE=	YES
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include"
CONFIGURE_ARGS=	--with-mysqllog --with-db3 -without-db4 --with-pcre --without-perl
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN8=		lmtpd.8
DOCS=		NEWS README TODO

post-install:
	${INSTALL_DATA} ${WRKSRC}/samples/lmtpd.conf \
		${PREFIX}/etc/lmtpd.conf.dist
	${INSTALL_SCRIPT} ${WRKSRC}/lmtpdlogsum/lmtpdlogsum.pl \
		${PREFIX}/bin/lmtpdlogsum
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
