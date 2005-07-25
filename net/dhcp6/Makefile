# New ports collection makefile for:	dhcp6
# Date created:		30 July 2004
# Whom:			sumikawa
#
# $FreeBSD$
#

PORTNAME=	dhcp6
PORTVERSION=	20050723a
CATEGORIES=	net ipv6
MASTER_SITES=	ftp://ftp.kame.net/pub/kame/misc/
DISTNAME=	kame-${PORTNAME}-${PORTVERSION}

MAINTAINER=	sumikawa@FreeBSD.org
COMMENT=		KAME DHCP6 client and server

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_RC_SUBR=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--sysconfdir=${LOCALBASE}/etc --with-localdbdir=/var/db
USE_REINPLACE=	yes

MAN5=		dhcp6c.conf.5 dhcp6s.conf.5
MAN8=		dhcp6c.8 dhcp6s.8 dhcp6relay.8 dhcp6ctl.8

RC_SCRIPTS=	dhcp6c.sh dhcp6relay.sh dhcp6s.sh
RC_SCRIPTS_SUB=	PREFIX=${PREFIX} \
		RC_SUBR=${RC_SUBR}

post-patch:
.for file in ${MAN5} ${MAN8}
	${REINPLACE_CMD} -e 's|/usr/local/v6/etc|${LOCALBASE}/etc|' \
		${WRKSRC}/${file}
.endfor
.for f in ${RC_SCRIPTS}
	@${SED} ${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${FILESDIR}/${f} > ${WRKDIR}/${f}
.endfor

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/COPYRIGHT ${DOCSDIR}
.endif
	${INSTALL_DATA} ${WRKSRC}/dhcp6c.conf.sample ${PREFIX}/etc
	${INSTALL_DATA} ${WRKSRC}/dhcp6s.conf.sample ${PREFIX}/etc
.for f in ${RC_SCRIPTS}
	@${INSTALL_SCRIPT} ${WRKDIR}/${f} ${PREFIX}/etc/rc.d/${f}
.endfor

.include <bsd.port.mk>
