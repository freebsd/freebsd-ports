# New ports collection makefile for:	dansguardian
# Date created:				March 26, 2002
# Whom:					Freddie Cash <fcash@sd73.bc.ca>
#
# $FreeBSD$
#

PORTNAME=	dansguardian
PORTVERSION=	2.6.1.6
CATEGORIES=	www
MASTER_SITES=	# empty, see below
DISTNAME=	DansGuardian-${PORTVERSION:R}-${PORTVERSION:E}.source

MAINTAINER=	fcash@sd73.bc.ca
COMMENT=	A fast, feature-rich web content filter for Squid proxy servers

RUN_DEPENDS=	${LOCALBASE}/sbin/squid:${PORTSDIR}/www/squid24:install \
		${LOCALBASE}/sbin/httpd:${PORTSDIR}/${APACHE_PORT}:install

CONFLICTS=	dansguardian-devel

WRKSRC=		${WRKDIR}/DansGuardian-${PORTVERSION:R}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--bindir=/sbin/ \
		--sysconfdir=/etc/dansguardian/ \
		--sysvdir=/etc/rc.d/ \
		--mandir=/man/ \
		--logdir=/var/log/ \
		--cgidir=/www/cgi-bin/ \
		--piddir=/var/run/

DG_URL=		http://dansguardian.org/index.php?page=copyright2

MAN8=		dansguardian.8

NO_CDROM=	"Commercial download is restricted.  Check ${DG_URL} for more info"
NO_PACKAGE=	"Redistribution is restricted.  Check ${DG_URL} for more info"
RESTRICTED=	${NO_PACKAGE}

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 500000 || defined(WITH_GCC3)
CONFIGURE_ARGS+=	--gccver=3
.else
CONFIGURE_ARGS+=	--gccver=2
.endif

.if !(exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}))
IGNORE=	"Commercial source download is restricted.  Please visit and read ${DG_URL} and download ${DISTNAME}${EXTRACT_SUFX} into ${DISTDIR} before running make"
.endif

post-install:
	@${CAT} pkg-message

.include <bsd.port.post.mk>
