# New ports collection makefile for:	rssh
# Date created:				Fri Apr 16 02:04:33 CEST 2004
# Whom:					enigmatyc
#
# $FreeBSD$
#

PORTNAME=	rssh
PORTVERSION=	2.3.4
CATEGORIES=	shells security
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Restricted Secure SHell only for sftp or/and scp

GNU_CONFIGURE=	yes

MAN1=		rssh.1
MAN5=		rssh.conf.5

OPTIONS_DEFINE=	RDIST
RDIST_DESC=	rdist support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MRDIST}
RUN_DEPENDS+=	${LOCALBASE}/bin/rdist6:${PORTSDIR}/net/rdist6
CONFIGURE_ARGS+=--with-rdist=${LOCALBASE}/bin/rdist6
.endif

post-patch:
	@${REINPLACE_CMD} -E -e 's,(\$$\(DESTDIR\)\$$\(sysconfdir\)/\$$\$$f),\1.dist,g' \
		${WRKSRC}/Makefile.in

post-install:
	@${ECHO_MSG} "updating /etc/shells"
	@${CP} /etc/shells /etc/shells.bak
	@(${GREP} -v ${PREFIX}/bin/${PORTNAME} /etc/shells.bak; \
		${ECHO_CMD} ${PREFIX}/bin/${PORTNAME}) > /etc/shells
	@${RM} /etc/shells.bak

.include <bsd.port.mk>
