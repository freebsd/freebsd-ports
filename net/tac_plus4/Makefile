# New ports collection makefile for:	tac_plus
# Date created:		4 Mar 1997
# Whom:			Igor Vinokurov <igor@zynaps.ru>
#
# $FreeBSD$
#

PORTNAME=	tac_plus
PORTVERSION=	F4.0.4.8
CATEGORIES=	net security
MASTER_SITES=	ftp://ftp.shrubbery.net/pub/tac_plus/
DISTNAME=	tacacs+-F4.0.4.8

MAINTAINER=	marcus@FreeBSD.org
COMMENT=	The Cisco remote authentication/authorization/accounting server

USE_PERL5_BUILD=yes
GNU_CONFIGURE=	yes
USE_RC_SUBR=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN5=		tac_plus.conf.5
MAN8=		tac_plus.8 tac_pwd.8

CONFLICTS=	ru-tac+ia-[0-9]* tac_plus-libradius-[0-9]*
RC_SCRIPTS_SUB=	PREFIX=${PREFIX} RC_SUBR=${RC_SUBR}

# check expiration dates against 'expire' field of master.passwd file
.if defined(TAC_EXPIRE_MASTER_PASSWD)
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-bb
.endif

# finger output differs for CISCO IOS versions 11 and 12.
# Define version of your IOS (default is 12):
# Example: make TAC_IOS_VERSION=11
#
.if defined(TAC_IOS_VERSION)
CFLAGS+=	-DTAC_IOS_VERSION=${TAC_IOS_VERSION}
.else
CFLAGS+=	-DTAC_IOS_VERSION=12
.endif

.if exists(/usr/include/skey.h) && !defined(WITHOUT_SKEY)
CONFIGURE_ARGS+=	--with-skey
.else
CONFIGURE_ARGS+=	--without-skey
.endif

.if exists(/usr/include/opie.h) && !defined(WITHOUT_OPIE)
CFLAGS+=	-DOPIE
CONFIGURE_ENV+=	LIBS="-lopie -lmd"
.endif

post-patch:
	@${SED} ${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${FILESDIR}/tac_plus.sh > ${WRKSRC}/tac_plus.sh
	@${REINPLACE_CMD} -e 's|skey_get_algorithm|skeychallenge|g' \
		${WRKSRC}/configure

post-install:
	${INSTALL_DATA} ${FILESDIR}/tac_plus.conf.example ${PREFIX}/etc
	${INSTALL_SCRIPT} ${WRKSRC}/tac_plus.sh ${PREFIX}/etc/rc.d/tac_plus.sh
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/tac_plus
	${INSTALL_DATA} ${WRKSRC}/users_guide ${PREFIX}/share/doc/tac_plus
	${INSTALL_SCRIPT} ${WRKSRC}/convert.pl ${PREFIX}/share/doc/tac_plus
.endif

.include <bsd.port.mk>
