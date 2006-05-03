# New ports collection makefile for:    verlihub-plugins
# Date created:                 26 August 2004
# Whom:                         Hurbold
#
# $FreeBSD$
#

PORTNAME=       verlihub-plugins
PORTVERSION=    0.1
CATEGORIES=     net-p2p
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=     verlihub
DISTNAME=	vh_plugins-0.1

MAINTAINER=     hurbold@yahoo.com
COMMENT=        Plugins for the Verlihub Linux/Unix Direct Connect Hub Software

BUILD_DEPENDS=	${LOCALBASE}/bin/verlihub:${PORTSDIR}/net-p2p/verlihub
LIB_DEPENDS=	lua.5:${PORTSDIR}/lang/lua50

WRKSRC=         ${WRKDIR}/vh_plugins-0.1

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	%%PREFIX%%/include/verlihub
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include -I${LOCALBASE}/include/verlihub -I${LOCALBASE}/include/mysql"

DATADIR=	${PREFIX}/share/${PORTNAME}

post-install:
	@${MKDIR} ${DATADIR}
	@${MKDIR} ${DATADIR}/extra
	${INSTALL_DATA} ${WRKSRC}/basic/chatroom/.libs/libchatroom_pi.so ${DATADIR}/libchatroom_pi.so
	${INSTALL_DATA} ${WRKSRC}/basic/floodprot/.libs/libfloodprot.so ${DATADIR}/libfloodprot_pi.so
	${INSTALL_DATA} ${WRKSRC}/basic/forbid/.libs/libforbid_pi.so ${DATADIR}/libforbid_pi.so
	${INSTALL_DATA} ${WRKSRC}/basic/funny/.libs/libfunny_pi.so ${DATADIR}/libfunny_pi.so
	${INSTALL_DATA} ${WRKSRC}/basic/iplog/.libs/libiplog_pi.so ${DATADIR}/libiplog_pi.so
	${INSTALL_DATA} ${WRKSRC}/basic/isp/.libs/libisp_pi.so ${DATADIR}/libisp_pi.so
	${INSTALL_DATA} ${WRKSRC}/basic/messanger/.libs/libmessanger_pi.so ${DATADIR}/libmessanger_pi.so
	${INSTALL_DATA} ${WRKSRC}/basic/replacer/.libs/libreplace_pi.so ${DATADIR}/libreplace_pi.so
	${INSTALL_DATA} ${WRKSRC}/basic/stats/.libs/libstats_pi.so ${DATADIR}/libstats_pi.so
	${INSTALL_DATA} ${WRKSRC}/extra/lua/src/.libs/liblua_pi.so ${DATADIR}/extra/liblua_pi.so
	${INSTALL_DATA} ${WRKSRC}/extra/perl/src/.libs/libperl_pi.so ${DATADIR}/extra/libperl_pi.so

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 502010
USE_GCC=	3.3
.endif

.if ${OSVERSION} > 502126
BROKEN=		Does not compile with gcc 3.4
.endif

.if ${PERL_LEVEL} < 500800
IGNORE=		requires perl 5.8 or later. Install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
