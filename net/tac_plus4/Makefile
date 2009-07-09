# New ports collection makefile for:	tac_plus
# Date created:		4 Mar 1997
# Whom:			Igor Vinokurov <igor@zynaps.ru>
#
# $FreeBSD$
#

PORTNAME=	tac_plus
PORTVERSION=	F4.0.4.18
CATEGORIES=	net security
MASTER_SITES=	ftp://ftp.shrubbery.net/pub/tac_plus/
DISTNAME=	tacacs+-F4.0.4.18

MAINTAINER=	marcus@FreeBSD.org
COMMENT=	The Cisco remote authentication/authorization/accounting server

USE_PERL5_BUILD=yes
GNU_CONFIGURE=	yes
USE_RC_SUBR=	tac_plus
CONFIGURE_ARGS=	--with-groupid=$$(/usr/bin/id -g tacacs 2>/dev/null || echo '559') \
		--with-userid=$$(/usr/bin/id -u tacacs 2>/dev/null || echo '559')

MAN5=		tac_plus.conf.5
MAN8=		tac_plus.8 tac_pwd.8

CONFLICTS=	ru-tac+ia-[0-9]* tac_plus-libradius-[0-9]*

# check expiration dates against 'expire' field of master.passwd file
.if defined(TAC_EXPIRE_MASTER_PASSWD)
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-bb
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
	@${REINPLACE_CMD} -e 's|skey_get_algorithm|skeychallenge|g' \
		${WRKSRC}/configure

post-install:
	${INSTALL_DATA} ${FILESDIR}/tac_plus.conf.example ${PREFIX}/etc
.if !defined(PACKAGE_BUILDING)
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/tac_plus
	${INSTALL_DATA} ${WRKSRC}/users_guide ${PREFIX}/share/doc/tac_plus
	${INSTALL_SCRIPT} ${WRKSRC}/tac_convert ${PREFIX}/share/doc/tac_plus
.endif

.include <bsd.port.mk>
