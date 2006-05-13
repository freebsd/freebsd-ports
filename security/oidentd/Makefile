# New ports collection makefile for:	oidentd
# Date created:		29 Mar 2000
# Whom:			Trevor Johnson
#
# $FreeBSD$
#

PORTNAME=	oidentd
PORTVERSION=	2.0.7
PORTREVISION=	8
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ojnk

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	Ident server that supports user-defined ident strings

USE_RC_SUBR=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN5=		oidentd.conf.5 oidentd_masq.conf.5
MAN8=		oidentd.8
PLIST_FILES=	sbin/oidentd etc/rc.d/oidentd.sh etc/oidentd.conf.sample \
		etc/oidentd_masq.conf.sample

post-patch:
	@${REINPLACE_CMD} -e 's,/etc/,${PREFIX}&,g' ${WRKSRC}/src/oidentd.h

post-build:
	@${SED} -e 's,%%PREFIX%%,${PREFIX},g' \
		-e 's,%%RC_SUBR%%,${RC_SUBR},g' \
		<${FILESDIR}/oidentd.sh >${WRKDIR}/oidentd.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/oidentd ${PREFIX}/sbin
	${INSTALL_DATA} ${MAN5:S,^,${FILESDIR}/,:S,5$,sample,} ${PREFIX}/etc
	${INSTALL_SCRIPT} ${WRKDIR}/oidentd.sh ${PREFIX}/etc/rc.d
.if !defined(NO_INSTALL_MANPAGES)
.for MANFILE in ${MAN5} ${MAN8}
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},g' ${WRKSRC}/doc/${MANFILE}
.endfor
	${INSTALL_MAN} ${MAN5:S,^,${WRKSRC}/doc/,} ${PREFIX}/man/man5
	${INSTALL_MAN} ${MAN8:S,^,${WRKSRC}/doc/,} ${PREFIX}/man/man8
.endif

.include <bsd.port.mk>
