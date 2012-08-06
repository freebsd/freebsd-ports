# New ports collection makefile for:	uhub
# Date created:		16 Oct 2009
# Whom:			Yashin Dmitry <yashin.dm@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	uhub
PORTVERSION=	0.4.0
CATEGORIES=	net-p2p
MASTER_SITES=	http://www.extatic.org/downloads/uhub/
DISTFILES=	${PORTNAME}-${PORTVERSION}-src${EXTRACT_SUFX}

MAINTAINER=	yashin.dm@gmail.com
COMMENT=	High performance peer-to-peer hub for the ADC network

LICENSE=	GPLv3

USE_PERL5_BUILD=yes
USE_GMAKE=	yes
USE_SQLITE=	yes

USE_RC_SUBR=	uhub
USERS=		uhub
GROUPS=		uhub
SHAREGRP=	uhub
SHAREMODE=	640

MAKEFILE=	${WRKSRC}/GNUmakefile

OPTIONS_DEFINE=	DEBUG OPENSSL
OPENSSL_DESC=	Enable OpenSSL Support (experimental)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOPENSSL}
USE_OPENSSL=	yes
MAKE_ARGS+=	USE_SSL=YES
.else
MAKE_ARGS+=	USE_SSL=NO
.endif

.if ${PORT_OPTIONS:MDEBUG}
CFLAGS+=	-ggdb -DDEBUG
.else
CFLAGS+=	-DNDEBUG
.endif

.include <bsd.port.pre.mk>

CFLAGS+=	-I./src/ -I${LOCALBASE}/include
MAKE_ARGS+=	UHUB_PREFIX="${PREFIX}" UHUB_CONF_DIR="${PREFIX}/etc/uhub" \
		SILENT=NO CC="${CC}" CFLAGS="${CFLAGS}"

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/uhub/|${PREFIX}&|' ${WRKSRC}/doc/uhub.conf
	@${REINPLACE_CMD} -e 's|/etc/uhub/|${PREFIX}&|' ${WRKSRC}/src/uhub.h

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/uhub ${PREFIX}/bin/uhub
	@${MKDIR} ${PREFIX}/etc/uhub
	@${INSTALL_DATA} ${WRKSRC}/doc/uhub.conf ${PREFIX}/etc/uhub/uhub.conf.sample
	@${INSTALL_DATA} ${WRKSRC}/doc/users.conf ${PREFIX}/etc/uhub/users.conf.sample
	@${INSTALL_DATA} /dev/null ${PREFIX}/etc/uhub/motd.txt.sample
	@${INSTALL_DATA} /dev/null ${PREFIX}/etc/uhub/rules.txt.sample
.for i in uhub.conf users.conf motd.txt rules.txt
	@[ ! -f ${PREFIX}/etc/uhub/${i} ] \
	&& ${CP} -p ${PREFIX}/etc/uhub/${i}.sample ${PREFIX}/etc/uhub/${i}
.endfor

.include <bsd.port.post.mk>
