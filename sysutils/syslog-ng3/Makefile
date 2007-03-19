# New ports collection makefile for:	syslog-ng
# Date created:		10 november 1006
# Whom:			Ivan Lago <ivan.lago@ifom-ieo-campus.it>
#
# $FreeBSD$
#

PORTNAME=	syslog-ng
PORTVERSION=	2.0.0
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.balabit.com/downloads/syslog-ng/2.0/src/

MAINTAINER=	ivan.lago@ifom-ieo-campus.it
COMMENT=	A powerful syslogd replacement

MAN5=		syslog-ng.conf.5
MAN8=		syslog-ng.8

USE_RC_SUBR=	syslog-ng.sh
GNU_CONFIGURE=	yes
USE_GCC=	3.3+
NO_LATEST_LINK=	yes
PKGMESSAGE=	${WRKDIR}/MESSAGE

LIB_DEPENDS=	glib-2.0:${PORTSDIR}/devel/glib20 \
		evtlog.0:${PORTSDIR}/sysutils/eventlog

.if defined(WITH_TCP_WRAPPERS)
CONFIGURE_ARGS+=--enable-tcp-wrapper
.endif

post-patch:
	@${REINPLACE_CMD} -e 's:__PREFIX__:${PREFIX}:g' ${WRKSRC}/src/syslog-ng.h

post-build:
	@${SED} -e 's,__PREFIX__,${PREFIX},g' ${PKGDIR}/pkg-message > ${PKGMESSAGE}

post-install:
.if !defined(NOPORTDOCS)
	${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} \
			${PREFIX}/share/doc/syslog-ng \
			${PREFIX}/share/doc/syslog-ng/sgml
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${PREFIX}/share/doc/syslog-ng
	${INSTALL_DATA} ${WRKSRC}/COPYING ${PREFIX}/share/doc/syslog-ng
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${PREFIX}/share/doc/syslog-ng
	${INSTALL_DATA} ${WRKSRC}/NEWS ${PREFIX}/share/doc/syslog-ng
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/syslog-ng
.endif
	@if [ ! -f ${PREFIX}/etc/syslog-ng/syslog-ng.conf.sample ]; then \
		${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} ${PREFIX}/etc/syslog-ng; \
		${INSTALL_DATA} ${FILESDIR}/syslog-ng.conf.sample ${PREFIX}/etc/syslog-ng; \
	fi
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
