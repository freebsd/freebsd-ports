# New ports collection makefile for:	uhub
# Date created:		16 Oct 2009
# Whom:			Yashin Dmitry <yashin.dm@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	uhub
PORTVERSION=	0.3.2
CATEGORIES=	net-p2p
MASTER_SITES=	http://www.extatic.org/downloads/uhub/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	yashin.dm@gmail.com
COMMENT=	High performance peer-to-peer hub for the ADC network

USE_PERL5=	yes
USE_GMAKE=	yes

USE_RC_SUBR=	uhub.sh

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
MAKEFILE=	${WRKSRC}/GNUmakefile

OPTIONS=	OPENSSL		"Enable SSL support (experimental)" off

.include <bsd.port.pre.mk>

.if defined(WITH_OPENSSL)
.include "${PORTSDIR}/Mk/bsd.openssl.mk"
MAKE_ARGS=	USE_SSL=YES
CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/uhub/|${PREFIX}&|' ${WRKSRC}/doc/uhub.conf

post-install:
	@${INSTALL_DATA} ${WRKSRC}/doc/uhub.conf ${PREFIX}/etc/uhub/uhub.conf.sample
	@${INSTALL_DATA} ${WRKSRC}/doc/users.conf ${PREFIX}/etc/uhub/users.conf.sample
	@if [ -f ${PREFIX}/etc/uhub/motd.txt ]; then \
		${TOUCH} ${PREFIX}/etc/uhub/motd.txt.sample ; \
	fi
	@if [ -f ${PREFIX}/etc/uhub/rules.txt ]; then \
		${TOUCH} ${PREFIX}/etc/uhub/rules.txt.sample ; \
	fi

.include <bsd.port.post.mk>
