# Ports collection makefile for:	smtptrapd
# Date created:				19 March 2005
# Whom:					Anders Nordby <anders@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	smtptrapd
PORTVERSION=	1.1
CATEGORIES=	mail
MASTER_SITES=	http://smtptrapd.inodes.org/

MAINTAINER=	anders@FreeBSD.org
COMMENT=	RFC 2821 compliant SMTP service that always returns a 4xx soft error

USE_RC_SUBR=	yes
SED_SCRIPT=	-e 's|%%PREFIX%%|${PREFIX}|g;s|%%RC_SUBR%%|${RC_SUBR}|g'

PLIST_FILES=	bin/smtptrapd

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
LIB_DEPENDS+=	lthread.2:${PORTSDIR}/devel/linuxthreads

CFLAGS+=	${PTHREAD_CFLAGS} -L${LOCALBASE}/lib -I${LOCALBASE}/include/pthread/linuxthreads -llthread -llgcc_r
.else
CFLAGS+=	${PTHREAD_CFLAGS} ${PTHREAD_LIBS}
.endif

do-build:
	(cd ${WRKSRC} && ${CC} ${CFLAGS} -o smtptrapd smtptrapd.c)
	${SED} ${SED_SCRIPT} ${FILESDIR}/smtptrapd.sh >${WRKSRC}/smtptrapd.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/smtptrapd ${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/smtptrapd.sh ${PREFIX}/etc/rc.d/smtptrapd.sh
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
