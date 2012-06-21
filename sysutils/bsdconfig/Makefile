# New ports collection makefile for:	bsdconfig
# Date created:				19 June 2012
# Whom:					Devin Teske <dteske@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bsdconfig
PORTVERSION=	0.7.1
CATEGORIES=	sysutils
MASTER_SITES=	http://druidbsd.sourceforge.net/download/bsdconfig/
DISTNAME=	${PORTNAME}.120620
EXTRACT_SUFX=	.txz

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	${DISTNAME}-${PORTVERSION}.diff.gz

MAINTAINER=	dteske@FreeBSD.org
COMMENT=	Utility to configure various aspects of FreeBSD

LICENSE=	BSD

NO_WRKSUBDIR=	yes

BSDCFG_LIBE=	libexec/${PORTNAME}

# Default man(1) section path-prefix
MANDIR?=	${MANPREFIX}/man/man
MAN8=		${PORTNAME}.8
MANCOMPRESSED=	yes

PLIST_FILES=	\
	sbin/${PORTNAME}                                                     \
	share/examples/${PORTNAME}/bsdconfigrc                               \
	${BSDCFG_LIBE}/020.docsinstall/INDEX                                 \
	${BSDCFG_LIBE}/020.docsinstall/INDEX.EN_US.ISO8859-1                 \
	${BSDCFG_LIBE}/020.docsinstall/USAGE                                 \
	${BSDCFG_LIBE}/020.docsinstall/USAGE.EN_US.ISO8859-1                 \
	${BSDCFG_LIBE}/020.docsinstall/docsinstall                           \
	${BSDCFG_LIBE}/020.docsinstall/include/messages.subr                 \
	${BSDCFG_LIBE}/020.docsinstall/include/messages.subr.EN_US.ISO8859-1 \
	${BSDCFG_LIBE}/040.password/INDEX                                    \
	${BSDCFG_LIBE}/040.password/INDEX.EN_US.ISO8859-1                    \
	${BSDCFG_LIBE}/040.password/USAGE                                    \
	${BSDCFG_LIBE}/040.password/USAGE.EN_US.ISO8859-1                    \
	${BSDCFG_LIBE}/040.password/include/messages.subr                    \
	${BSDCFG_LIBE}/040.password/include/messages.subr.EN_US.ISO8859-1    \
	${BSDCFG_LIBE}/040.password/include/password.subr                    \
	${BSDCFG_LIBE}/040.password/password                                 \
	${BSDCFG_LIBE}/050.diskmgmt/INDEX                                    \
	${BSDCFG_LIBE}/050.diskmgmt/INDEX.EN_US.ISO8859-1                    \
	${BSDCFG_LIBE}/050.diskmgmt/USAGE                                    \
	${BSDCFG_LIBE}/050.diskmgmt/USAGE.EN_US.ISO8859-1                    \
	${BSDCFG_LIBE}/050.diskmgmt/diskmgmt                                 \
	${BSDCFG_LIBE}/050.diskmgmt/include/messages.subr                    \
	${BSDCFG_LIBE}/050.diskmgmt/include/messages.subr.EN_US.ISO8859-1    \
	${BSDCFG_LIBE}/070.usermgmt/INDEX                                    \
	${BSDCFG_LIBE}/070.usermgmt/INDEX.EN_US.ISO8859-1                    \
	${BSDCFG_LIBE}/070.usermgmt/USAGE                                    \
	${BSDCFG_LIBE}/070.usermgmt/USAGE.EN_US.ISO8859-1                    \
	${BSDCFG_LIBE}/070.usermgmt/groupadd                                 \
	${BSDCFG_LIBE}/070.usermgmt/groupdel                                 \
	${BSDCFG_LIBE}/070.usermgmt/groupedit                                \
	${BSDCFG_LIBE}/070.usermgmt/groupinput                               \
	${BSDCFG_LIBE}/070.usermgmt/include/group_input.subr                 \
	${BSDCFG_LIBE}/070.usermgmt/include/messages.subr                    \
	${BSDCFG_LIBE}/070.usermgmt/include/messages.subr.EN_US.ISO8859-1    \
	${BSDCFG_LIBE}/070.usermgmt/include/user_input.subr                  \
	${BSDCFG_LIBE}/070.usermgmt/useradd                                  \
	${BSDCFG_LIBE}/070.usermgmt/userdel                                  \
	${BSDCFG_LIBE}/070.usermgmt/useredit                                 \
	${BSDCFG_LIBE}/070.usermgmt/userinput                                \
	${BSDCFG_LIBE}/070.usermgmt/usermgmt                                 \
	${BSDCFG_LIBE}/080.console/INDEX                                     \
	${BSDCFG_LIBE}/080.console/INDEX.EN_US.ISO8859-1                     \
	${BSDCFG_LIBE}/080.console/USAGE                                     \
	${BSDCFG_LIBE}/080.console/USAGE.EN_US.ISO8859-1                     \
	${BSDCFG_LIBE}/080.console/console                                   \
	${BSDCFG_LIBE}/080.console/font                                      \
	${BSDCFG_LIBE}/080.console/include/messages.subr                     \
	${BSDCFG_LIBE}/080.console/include/messages.subr.EN_US.ISO8859-1     \
	${BSDCFG_LIBE}/080.console/keymap                                    \
	${BSDCFG_LIBE}/080.console/repeat                                    \
	${BSDCFG_LIBE}/080.console/saver                                     \
	${BSDCFG_LIBE}/080.console/screenmap                                 \
	${BSDCFG_LIBE}/080.console/ttys                                      \
	${BSDCFG_LIBE}/090.timezone/INDEX                                    \
	${BSDCFG_LIBE}/090.timezone/INDEX.EN_US.ISO8859-1                    \
	${BSDCFG_LIBE}/090.timezone/USAGE                                    \
	${BSDCFG_LIBE}/090.timezone/USAGE.EN_US.ISO8859-1                    \
	${BSDCFG_LIBE}/090.timezone/include/continents.subr                  \
	${BSDCFG_LIBE}/090.timezone/include/countries.subr                   \
	${BSDCFG_LIBE}/090.timezone/include/iso3166.subr                     \
	${BSDCFG_LIBE}/090.timezone/include/menus.subr                       \
	${BSDCFG_LIBE}/090.timezone/include/messages.subr                    \
	${BSDCFG_LIBE}/090.timezone/include/messages.subr.EN_US.ISO8859-1    \
	${BSDCFG_LIBE}/090.timezone/include/zones.subr                       \
	${BSDCFG_LIBE}/090.timezone/timezone                                 \
	${BSDCFG_LIBE}/110.mouse/INDEX                                       \
	${BSDCFG_LIBE}/110.mouse/INDEX.EN_US.ISO8859-1                       \
	${BSDCFG_LIBE}/110.mouse/USAGE                                       \
	${BSDCFG_LIBE}/110.mouse/USAGE.EN_US.ISO8859-1                       \
	${BSDCFG_LIBE}/110.mouse/disable                                     \
	${BSDCFG_LIBE}/110.mouse/enable                                      \
	${BSDCFG_LIBE}/110.mouse/flags                                       \
	${BSDCFG_LIBE}/110.mouse/include/messages.subr                       \
	${BSDCFG_LIBE}/110.mouse/include/messages.subr.EN_US.ISO8859-1       \
	${BSDCFG_LIBE}/110.mouse/mouse                                       \
	${BSDCFG_LIBE}/110.mouse/port                                        \
	${BSDCFG_LIBE}/110.mouse/type                                        \
	${BSDCFG_LIBE}/120.networking/INDEX                                  \
	${BSDCFG_LIBE}/120.networking/INDEX.EN_US.ISO8859-1                  \
	${BSDCFG_LIBE}/120.networking/USAGE                                  \
	${BSDCFG_LIBE}/120.networking/USAGE.EN_US.ISO8859-1                  \
	${BSDCFG_LIBE}/120.networking/defaultrouter                          \
	${BSDCFG_LIBE}/120.networking/devices                                \
	${BSDCFG_LIBE}/120.networking/hostname                               \
	${BSDCFG_LIBE}/120.networking/include/common.subr                    \
	${BSDCFG_LIBE}/120.networking/include/device.subr                    \
	${BSDCFG_LIBE}/120.networking/include/hostname.subr                  \
	${BSDCFG_LIBE}/120.networking/include/ipaddr.subr                    \
	${BSDCFG_LIBE}/120.networking/include/media.subr                     \
	${BSDCFG_LIBE}/120.networking/include/messages.subr                  \
	${BSDCFG_LIBE}/120.networking/include/messages.subr.EN_US.ISO8859-1  \
	${BSDCFG_LIBE}/120.networking/include/netmask.subr                   \
	${BSDCFG_LIBE}/120.networking/include/resolv.subr                    \
	${BSDCFG_LIBE}/120.networking/include/routing.subr                   \
	${BSDCFG_LIBE}/120.networking/nameservers                            \
	${BSDCFG_LIBE}/120.networking/networking                             \
	${BSDCFG_LIBE}/130.security/INDEX                                    \
	${BSDCFG_LIBE}/130.security/INDEX.EN_US.ISO8859-1                    \
	${BSDCFG_LIBE}/130.security/USAGE                                    \
	${BSDCFG_LIBE}/130.security/USAGE.EN_US.ISO8859-1                    \
	${BSDCFG_LIBE}/130.security/include/messages.subr                    \
	${BSDCFG_LIBE}/130.security/include/messages.subr.EN_US.ISO8859-1    \
	${BSDCFG_LIBE}/130.security/kern_securelevel                         \
	${BSDCFG_LIBE}/130.security/security                                 \
	${BSDCFG_LIBE}/140.startup/INDEX                                     \
	${BSDCFG_LIBE}/140.startup/INDEX.EN_US.ISO8859-1                     \
	${BSDCFG_LIBE}/140.startup/USAGE                                     \
	${BSDCFG_LIBE}/140.startup/USAGE.EN_US.ISO8859-1                     \
	${BSDCFG_LIBE}/140.startup/include/messages.subr                     \
	${BSDCFG_LIBE}/140.startup/include/messages.subr.EN_US.ISO8859-1     \
	${BSDCFG_LIBE}/140.startup/include/rcconf.subr                       \
	${BSDCFG_LIBE}/140.startup/include/rcedit.subr                       \
	${BSDCFG_LIBE}/140.startup/include/rcvar.subr                        \
	${BSDCFG_LIBE}/140.startup/misc                                      \
	${BSDCFG_LIBE}/140.startup/rcadd                                     \
	${BSDCFG_LIBE}/140.startup/rcconf                                    \
	${BSDCFG_LIBE}/140.startup/rcdelete                                  \
	${BSDCFG_LIBE}/140.startup/rcedit                                    \
	${BSDCFG_LIBE}/140.startup/rcvar                                     \
	${BSDCFG_LIBE}/140.startup/startup                                   \
	${BSDCFG_LIBE}/150.ttys/INDEX                                        \
	${BSDCFG_LIBE}/150.ttys/INDEX.EN_US.ISO8859-1                        \
	${BSDCFG_LIBE}/150.ttys/USAGE                                        \
	${BSDCFG_LIBE}/150.ttys/USAGE.EN_US.ISO8859-1                        \
	${BSDCFG_LIBE}/150.ttys/include/messages.subr                        \
	${BSDCFG_LIBE}/150.ttys/include/messages.subr.EN_US.ISO8859-1        \
	${BSDCFG_LIBE}/150.ttys/ttys                                         \
	${BSDCFG_LIBE}/USAGE                                                 \
	${BSDCFG_LIBE}/USAGE.EN_US.ISO8859-1                                 \
	${BSDCFG_LIBE}/dot/INDEX                                             \
	${BSDCFG_LIBE}/dot/INDEX.EN_US.ISO8859-1                             \
	${BSDCFG_LIBE}/dot/USAGE                                             \
	${BSDCFG_LIBE}/dot/USAGE.EN_US.ISO8859-1                             \
	${BSDCFG_LIBE}/dot/dot                                               \
	${BSDCFG_LIBE}/dot/include/messages.subr                             \
	${BSDCFG_LIBE}/dot/include/messages.subr.EN_US.ISO8859-1             \
	${BSDCFG_LIBE}/include/common.subr                                   \
	${BSDCFG_LIBE}/include/dialog.subr                                   \
	${BSDCFG_LIBE}/include/messages.subr                                 \
	${BSDCFG_LIBE}/include/messages.subr.EN_US.ISO8859-1                 \
	${BSDCFG_LIBE}/include/mustberoot.subr                               \
	${BSDCFG_LIBE}/include/strings.subr                                  \
	${BSDCFG_LIBE}/include/sysrc.subr

PLIST_DIRS=	${BSDCFG_LIBE}/020.docsinstall/include \
		${BSDCFG_LIBE}/020.docsinstall         \
		${BSDCFG_LIBE}/040.password/include    \
		${BSDCFG_LIBE}/040.password            \
		${BSDCFG_LIBE}/050.diskmgmt/include    \
		${BSDCFG_LIBE}/050.diskmgmt            \
		${BSDCFG_LIBE}/070.usermgmt/include    \
		${BSDCFG_LIBE}/070.usermgmt            \
		${BSDCFG_LIBE}/080.console/include     \
		${BSDCFG_LIBE}/080.console             \
		${BSDCFG_LIBE}/090.timezone/include    \
		${BSDCFG_LIBE}/090.timezone            \
		${BSDCFG_LIBE}/110.mouse/include       \
		${BSDCFG_LIBE}/110.mouse               \
		${BSDCFG_LIBE}/120.networking/include  \
		${BSDCFG_LIBE}/120.networking          \
		${BSDCFG_LIBE}/130.security/include    \
		${BSDCFG_LIBE}/130.security            \
		${BSDCFG_LIBE}/140.startup/include     \
		${BSDCFG_LIBE}/140.startup             \
		${BSDCFG_LIBE}/150.ttys/include        \
		${BSDCFG_LIBE}/150.ttys                \
		${BSDCFG_LIBE}/dot/include             \
		${BSDCFG_LIBE}/dot                     \
		${BSDCFG_LIBE}/include                 \
		${BSDCFG_LIBE}                         \
		share/examples/bsdconfig

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 900030
BROKEN=		libdialog 20100428 or newer required.
.endif

post-patch:
	@${GREP} -Ilrs '^BSDCFG_LIBE=' ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} \
		-e 's|^\(BSDCFG_LIBE=\).*|\1"${PREFIX}/libexec/${PORTNAME}"|'
	@${REINPLACE_CMD} \
		-e 's|^\(BSDCONFIG=\).*|\1${PREFIX}/sbin/${PORTNAME}|' \
		${WRKSRC}/dot/dot

do-install:
	@( cd ${WRKSRC} && make \
		LIBEXECDIR="${PREFIX}/libexec" \
		MANDIR="${MANDIR}"             \
		SBINDIR="${PREFIX}/sbin"       \
		SHAREDIR="${PREFIX}/share"     \
		install                        )

.include <bsd.port.post.mk>
