# New ports collection makefile for:   drweb
# Date created:        14 August 2001
# Whom:                Anton Voronin <anton@chelcom.ru>
#
# $FreeBSD$
#

PORTNAME=	drweb
PORTVERSION=	4.33
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.drweb.ru/pub/drweb/unix/FreeBSD/411/ \
		ftp://ftp.drweb.ru/pub/drweb/unix/FreeBSD/54/

MAINTAINER=	support@spectrum.ru
COMMENT=	DrWeb antivirus suite

ONLY_FOR_ARCHS=	i386
NO_BUILD=	yes

RUN_DEPENDS=	${LOCALBASE}/bin/wget:${PORTSDIR}/ftp/wget

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
DISTNAME=	${PORTNAME}-${PORTVERSION}-freebsd411
.else
DISTNAME=	${PORTNAME}-${PORTVERSION}-freebsd54
.if ${OSVERSION} >= 600000
LIB_DEPENDS+=	c.5:${PORTSDIR}/misc/compat5x
.endif
.endif

WRKSRC=		${WRKDIR}/${DISTNAME}

DRWEB_PREFIX=	${PREFIX}/${PORTNAME}
DRWEB_VARPREFIX=/var/drweb

do-install:
	${INSTALL} -dv -m 0750 ${DRWEB_PREFIX}
	${INSTALL} -dv -m 0750 ${PREFIX}/etc/drweb
	${INSTALL} -dv -m 0750 ${DRWEB_VARPREFIX}
	${RM} -f ${WRKSRC}${LOCALBASE}/drweb/update.pl
	${TAR} -cf - -C ${WRKSRC}${LOCALBASE}/drweb . | \
		${TAR} -xf - -C ${DRWEB_PREFIX} \
		--exclude "*.static" --exclude "doc"
	${TAR} -cf - -C ${WRKSRC}/var/drweb/ . | \
		${TAR} -xf - -C ${DRWEB_VARPREFIX}
	${INSTALL_DATA} -m 0640 ${WRKSRC}${LOCALBASE}/etc/drweb/drweb32.ini \
		${PREFIX}/etc/drweb/drweb32.ini-distr
	if [ ! -f ${PREFIX}/etc/drweb/drweb32.ini ] ; then \
		${CP} ${PREFIX}/etc/drweb/drweb32.ini-distr \
		      ${PREFIX}/etc/drweb/drweb32.ini; \
	fi
	${INSTALL_DATA} -m 0640 ${WRKSRC}${LOCALBASE}/etc/drweb/email.ini \
		${PREFIX}/etc/drweb/email.ini-distr
	if [ ! -f ${PREFIX}/etc/drweb/email.ini ] ; then \
		${CP} ${PREFIX}/etc/drweb/email.ini-distr \
		${PREFIX}/etc/drweb/email.ini; \
	fi
	${INSTALL_SCRIPT} -m 0750 -b ${WRKSRC}${LOCALBASE}/etc/rc.d/00.drwebd.sh \
		${PREFIX}/etc/rc.d/00.drwebd.sh

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${TAR} -cf - -C ${WRKSRC}${LOCALBASE}/drweb/doc . | \
		${TAR} -xf - -C ${DOCSDIR}
.endif
	${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL ${DRWEB_PREFIX} ${DRWEB_VARPREFIX}

.include <bsd.port.post.mk>
