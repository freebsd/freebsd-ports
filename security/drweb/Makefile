# New ports collection makefile for:   drweb
# Date created:        14 August 2001
# Whom:                Anton Voronin <anton@chelcom.ru>
#
# $FreeBSD$
#

PORTNAME=	drweb
PORTVERSION=	4.33
PORTREVISION=	4
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.drweb.com/pub/drweb/unix/FreeBSD/61/:f61 \
		ftp://ftp.drweb.com/pub/drweb/unix/FreeBSD/55/:f55 \
		ftp://ftp.drweb.com/pub/drweb/unix/FreeBSD/411/:f411 \
		http://freebsd.spectrum.ru/distfiles/drweb/:f61,f55,f411
DIST_SUBDIR=	drweb

MAINTAINER=	support@spectrum.ru
COMMENT=	DrWeb antivirus suite

RUN_DEPENDS=	${LOCALBASE}/bin/wget:${PORTSDIR}/ftp/wget

IA32_BINARY_PORT=	yes
NO_BUILD=		yes
USE_RC_SUBR=		drwebd.sh

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
DISTNAME=	${PORTNAME}-${PORTVERSION}-freebsd411
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:f411
.elif ${OSVERSION} >= 601000
DISTNAME=	${PORTNAME}-${PORTVERSION}-freebsd61
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:f61
.else
DISTNAME=	${PORTNAME}-${PORTVERSION}-freebsd55
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:f55
.endif

WRKSRC=		${WRKDIR}/${DISTNAME}

DRWEB_PREFIX=	${PREFIX}/${PORTNAME}
DRWEB_VARPREFIX=/var/drweb

pre-install:
.if ${OSVERSION} < 500000
PLIST_SUB=	RU="@comment "
.else
PLIST_SUB=	RU=""
.endif

do-install:
	@${INSTALL} -dv -m 0750 ${DRWEB_PREFIX}
	@${INSTALL} -dv -m 0750 ${PREFIX}/etc/drweb
	@${INSTALL} -dv -m 0750 ${DRWEB_VARPREFIX}
	@${RM} -f ${WRKSRC}${LOCALBASE}/drweb/update.pl
	@${TAR} -cf - -C ${WRKSRC}${LOCALBASE}/drweb . | \
		${TAR} -xf - -C ${DRWEB_PREFIX} \
		--exclude "*.static" --exclude "doc"
	@${TAR} -cf - -C ${WRKSRC}/var/drweb/ . | \
		${TAR} -xf - -C ${DRWEB_VARPREFIX}
	@${INSTALL_DATA} -m 0640 ${WRKSRC}${LOCALBASE}/etc/drweb/drweb32.ini \
		${PREFIX}/etc/drweb/drweb32.ini-distr
	if [ ! -f ${PREFIX}/etc/drweb/drweb32.ini ] ; then \
		${CP} ${PREFIX}/etc/drweb/drweb32.ini-distr \
		      ${PREFIX}/etc/drweb/drweb32.ini; \
	fi
	@${INSTALL_DATA} -m 0640 ${WRKSRC}${LOCALBASE}/etc/drweb/email.ini \
		${PREFIX}/etc/drweb/email.ini-distr
	if [ ! -f ${PREFIX}/etc/drweb/email.ini ] ; then \
		${CP} ${PREFIX}/etc/drweb/email.ini-distr \
		${PREFIX}/etc/drweb/email.ini; \
	fi

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${TAR} -cf - -C ${WRKSRC}${LOCALBASE}/drweb/doc . | \
		${TAR} -xf - -C ${DOCSDIR}
.endif

	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL ${DRWEB_PREFIX} ${DRWEB_VARPREFIX} ${PREFIX}

.include <bsd.port.post.mk>
