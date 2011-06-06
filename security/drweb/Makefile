# New ports collection makefile for:   drweb
# Date created:        14 August 2001
# Whom:                Anton Voronin <anton@chelcom.ru>
#
# $FreeBSD$
#

PORTNAME=	drweb
PORTVERSION=	4.44.3
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.drweb.com/pub/drweb/unix/FreeBSD/70/ \
		http://freebsd.spectrum.ru/distfiles/drweb/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DrWeb antivirus suite

DEPRECATED=		fails to fetch (website rearranged)
EXPIRATION_DATE=	2011-08-06

IA32_BINARY_PORT=	yes
NO_BUILD=		yes
USE_RC_SUBR=		drwebd
USE_BZIP2=		yes

.include <bsd.port.pre.mk>

DISTNAME=	${PORTNAME}-${PORTVERSION}-unix-fbsd70
DIST_SUBDIR=	${PORTNAME}

WRKSRC=		${WRKDIR}/${DISTNAME}
DRWEB_PREFIX=	${PREFIX}/${PORTNAME}
DRWEB_VARPREFIX=/var/drweb

do-install:
	@${INSTALL} -dv -m 0750 ${DRWEB_PREFIX}
	@${INSTALL} -dv -m 0750 ${PREFIX}/etc/drweb
	@${INSTALL} -dv -m 0750 ${PREFIX}/etc/drweb/monitor
	@${INSTALL} -dv -m 0750 ${DRWEB_VARPREFIX}
	@${MKDIR} ${WRKSRC}${LOCALBASE}/drweb/update
	@${MV} ${WRKSRC}${LOCALBASE}/drweb/update.pl \
		${WRKSRC}${LOCALBASE}/drweb/update/update.pl
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
	@${INSTALL_DATA} -m 0640 \
		${WRKSRC}${LOCALBASE}/etc/drweb/monitor/daemon.mmc \
		${PREFIX}/etc/drweb/monitor/daemon.mmc

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${TAR} -cf - -C ${WRKSRC}${LOCALBASE}/drweb/doc . | \
		${TAR} -xf - -C ${DOCSDIR}
.endif

	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL ${DRWEB_PREFIX} ${DRWEB_VARPREFIX} ${PREFIX}

.include <bsd.port.post.mk>
