# New ports collection makefile for:	oidentd
# Date created:		29 Mar 2000
# Whom:			Trevor Johnson
#
# $FreeBSD$
#

PORTNAME=	oidentd
PORTVERSION=	2.0.7
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ojnk

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	Ident server that supports user-defined ident strings

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN5=		oidentd.conf.5 oidentd_masq.conf.5
MAN8=		oidentd.8

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500038
RC_SUBR=	/etc/rc.subr
.else
USE_RC_SUBR=	yes
.endif

post-build:
	@${SED} -e 's,%%PREFIX%%,${PREFIX},g' \
		-e 's,%%RC_SUBR%%,${RC_SUBR},g' \
		<${FILESDIR}/oidentd.sh >${WRKDIR}/oidentd.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/oidentd ${PREFIX}/sbin
	${INSTALL_DATA} ${MAN5:S,^,${FILESDIR}/,:S,5$,sample,} ${PREFIX}/etc
	${INSTALL_SCRIPT} ${WRKDIR}/oidentd.sh ${PREFIX}/etc/rc.d
	${INSTALL_MAN} ${MAN5:S,^,${WRKSRC}/doc/,} ${PREFIX}/man/man5
	${INSTALL_MAN} ${MAN8:S,^,${WRKSRC}/doc/,} ${PREFIX}/man/man8

.include <bsd.port.post.mk>
