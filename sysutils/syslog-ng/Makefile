# New ports collection makefile for:	syslog-ng
# Date created:		22 April 2000
# Whom:			Vince Valenti <vince@blue-box.net>
#
# $FreeBSD$
#

PORTNAME=	syslog-ng
PORTVERSION=	1.6.10
CATEGORIES=	sysutils
MASTER_SITES=	http://www.balabit.com/downloads/syslog-ng/1.6/src/ \
		http://www.balabit.com/downloads/syslog-ng/1.6/src/old/

MAINTAINER=	vince@blue-box.net
COMMENT=	A powerful syslogd replacement

MAN5=		syslog-ng.conf.5
MAN8=		syslog-ng.8

USE_RC_SUBR=	syslog-ng.sh
GNU_CONFIGURE=	yes
USE_GCC=	3.3+

PKGMESSAGE=	${WRKDIR}/MESSAGE

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
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${PREFIX}/share/doc/syslog-ng
	${INSTALL_DATA} ${WRKSRC}/NEWS ${PREFIX}/share/doc/syslog-ng
	${INSTALL_DATA} ${WRKSRC}/PORTS ${PREFIX}/share/doc/syslog-ng
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/syslog-ng
	${INSTALL_DATA} ${WRKSRC}/doc/sgml/syslog-ng.xml ${PREFIX}/share/doc/syslog-ng/sgml
	${INSTALL_DATA} ${WRKSRC}/doc/sgml/syslog-ng.html.tar.gz ${PREFIX}/share/doc/syslog-ng/sgml
	${INSTALL_DATA} ${WRKSRC}/doc/sgml/syslog-ng.txt ${PREFIX}/share/doc/syslog-ng/sgml
.endif
	@if [ ! -f ${PREFIX}/etc/syslog-ng/syslog-ng.conf.sample ]; then \
		${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} ${PREFIX}/etc/syslog-ng; \
		${INSTALL_DATA} ${FILESDIR}/syslog-ng.conf.sample ${PREFIX}/etc/syslog-ng; \
	fi
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
