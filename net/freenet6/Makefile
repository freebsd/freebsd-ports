# New ports collection makefile for:   freenet6
# Date created:        11 Oct 2001
# Whom:                Edwin Groothuis (edwin@mavetju.org)
#
# $FreeBSD$
#

PORTNAME=	freenet6
PORTVERSION=	0.9.6
PORTREVISION=	1
CATEGORIES=	net ipv6
MASTER_SITES=	# fetch manually
EXTRACT_SUFX=	.tgz

MAINTAINER=	edwin@mavetju.org

USE_REINPLACE=	yes

MAN8=		tspc.8
MAN5=		tspc.conf.5

PKGMESSAGE=	${WRKSRC}/pkg-message

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 400000
IGNORE=		This program might not be working on FreeBSD version below 4.0
.endif

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=		May not be automatically fetched due to licensing\
		restrictions. You MUST manually fetch the version\
		after reading and agreeing to the license at:\
		http://www.freenet6.net/cgi-bin/download.cgi?fn=${DISTFILES} \
		Once it has been downloaded, move it to\
		${DISTDIR} and then restart this build.\
		You also can register to use this service at\
		http://www.freenet6.net/cgi-bin/new_account.pl
.endif

NO_CDROM=	"Redistribution not allowed"
NO_PACKAGE=	"Redistribution not allowed"

.if ${OSVERSION} >= 440000
MAKE_ARGS=	target=freebsd44 installdir=${PREFIX}
.else
MAKE_ARGS=	target=freebsd4 installdir=${PREFIX}
.endif

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/bin/tspc ${PREFIX}/bin/tspc
	@${INSTALL_DATA} ${WRKSRC}/bin/tspc.conf ${PREFIX}/etc/tspc.conf.sample
	@${INSTALL_SCRIPT} ${WRKSRC}/template/checktunnel.sh ${PREFIX}/bin/checktunnel.sh
	@${INSTALL_SCRIPT} ${WRKSRC}/template/freebsd44.sh ${PREFIX}/bin/tspc-freebsd44.sh
	@${INSTALL_SCRIPT} ${WRKSRC}/template/freebsd4.sh ${PREFIX}/bin/tspc-freebsd4.sh
	@${INSTALL_MAN} ${WRKSRC}/man/man8/tspc.8 ${PREFIX}/man/man8
	@${INSTALL_MAN} ${WRKSRC}/man/man5/tspc.conf.5 ${PREFIX}/man/man5
	@${INSTALL_SCRIPT} ${WRKSRC}/freenet6.sh ${PREFIX}/etc/rc.d/

post-install:
	@${CAT} ${PKGMESSAGE}

post-patch:
	@${REINPLACE_CMD} -e "s|tspc.conf|${PREFIX}/etc/tspc.conf|" \
		${WRKSRC}/src/tspc.c

	@${CP} ${FILESDIR}/freenet6.sh.in ${WRKSRC}/freenet6.sh
	@${REINPLACE_CMD} -e "s|@@PREFIX@@|${PREFIX}|g" ${WRKSRC}/freenet6.sh

	@${CP} ${FILESDIR}/pkg-message.in ${WRKSRC}/pkg-message
	@${REINPLACE_CMD} -e "s|@@PREFIX@@|${PREFIX}|g" ${WRKSRC}/pkg-message

	@${REINPLACE_CMD} -e "s|@@PREFIX@@|${PREFIX}|g" \
		${WRKSRC}/man/man8/tspc.8

	@${REINPLACE_CMD} -e "s|@@PREFIX@@|${PREFIX}|g" \
		${WRKSRC}/man/man5/tspc.conf.5

.include <bsd.port.post.mk>
