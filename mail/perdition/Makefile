# New ports collection makefile for:	perdition
# Date created:				28 April 2001
# Whom:					Konstantinos Konstantinidis <kkonstan@daemon.gr>
#
# $FreeBSD$
#

PORTNAME=	perdition
PORTVERSION=	0.1.9
CATEGORIES=	mail net security
MASTER_SITES=	ftp://perdition.sourceforge.net/pub/perdition/%SUBDIR%/ \
		ftp://ftp.au.vergenet.net/pub/perdition/%SUBDIR%/ \
		ftp://ftp.nl.vergenet.net/pub/perdition/%SUBDIR%/ \
		ftp://ftp.jp.vergenet.net/pub/perdition/%SUBDIR%/ \
		ftp://ftp.us.vergenet.net/pub/perdition/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	intl.4:${PORTSDIR}/devel/gettext \
		popt.0:${PORTSDIR}/devel/popt \
		gdbm.2:${PORTSDIR}/databases/gdbm \
		vanessa_logger.0:${PORTSDIR}/devel/libvanessa_logger \
		vanessa_socket.0:${PORTSDIR}/devel/libvanessa_socket \
		vanessa_adt.0:${PORTSDIR}/devel/libvanessa_adt

MAN1=		makegdbm.1
MAN5=		perditiondb.5
MAN8=		perdition.8

USE_LIBTOOL=	YES
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
INSTALLS_SHLIB=	yes

post-extract:
	${MV} ${WRKSRC}/etc/perdition/perdition.conf \
		${WRKSRC}/etc/perdition/perdition.conf.sample
	${MV} ${WRKSRC}/perdition/db/gdbm/popmap \
		${WRKSRC}/perdition/db/gdbm/popmap.sample
	${MV} ${WRKSRC}/perdition/db/posix_regex/popmap.re \
		${WRKSRC}/perdition/db/posix_regex/popmap.re.sample

.include <bsd.port.mk>
