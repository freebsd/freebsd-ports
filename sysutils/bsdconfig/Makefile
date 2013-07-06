# Created by: Devin Teske <dteske@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bsdconfig
PORTVERSION=	0.9.0
CATEGORIES=	sysutils
MASTER_SITES=	http://druidbsd.sourceforge.net/download/bsdconfig/
DISTNAME=	${PORTNAME}.130705
EXTRACT_SUFX=	.txz

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	${DISTNAME}-${PORTVERSION}.diff.gz

MAINTAINER=	dteske@FreeBSD.org
COMMENT=	Utility to configure various aspects of FreeBSD

LICENSE=	BSD

NO_WRKSUBDIR=	yes

BSDCFG_LIBE=	libexec/${PORTNAME}
BSDCFG_SHARE=	share/${PORTNAME}

# Default man(1) section path-prefix
MANDIR?=	${MANPREFIX}/man/man
MAN8=		${PORTNAME}.8
MANCOMPRESSED=	yes

PLIST_FILES=	\
	sbin/${PORTNAME}                                                     \
	share/examples/${PORTNAME}/browse_packages.sh                        \
	share/examples/${PORTNAME}/bsdconfigrc                               \
	${BSDCFG_LIBE}/020.docsinstall/INDEX                                 \
	${BSDCFG_LIBE}/020.docsinstall/USAGE                                 \
	${BSDCFG_LIBE}/020.docsinstall/docsinstall                           \
	${BSDCFG_LIBE}/020.docsinstall/include/messages.subr                 \
	${BSDCFG_LIBE}/030.packages/INDEX                                    \
	${BSDCFG_LIBE}/030.packages/USAGE                                    \
	${BSDCFG_LIBE}/030.packages/include/messages.subr                    \
	${BSDCFG_LIBE}/030.packages/packages                                 \
	${BSDCFG_LIBE}/040.password/INDEX                                    \
	${BSDCFG_LIBE}/040.password/USAGE                                    \
	${BSDCFG_LIBE}/040.password/include/messages.subr                    \
	${BSDCFG_LIBE}/040.password/password                                 \
	${BSDCFG_LIBE}/050.diskmgmt/INDEX                                    \
	${BSDCFG_LIBE}/050.diskmgmt/USAGE                                    \
	${BSDCFG_LIBE}/050.diskmgmt/diskmgmt                                 \
	${BSDCFG_LIBE}/050.diskmgmt/include/messages.subr                    \
	${BSDCFG_LIBE}/070.usermgmt/INDEX                                    \
	${BSDCFG_LIBE}/070.usermgmt/USAGE                                    \
	${BSDCFG_LIBE}/070.usermgmt/groupadd                                 \
	${BSDCFG_LIBE}/070.usermgmt/groupdel                                 \
	${BSDCFG_LIBE}/070.usermgmt/groupedit                                \
	${BSDCFG_LIBE}/070.usermgmt/groupinput                               \
	${BSDCFG_LIBE}/070.usermgmt/include/messages.subr                    \
	${BSDCFG_LIBE}/070.usermgmt/include/usermgmt.hlp                     \
	${BSDCFG_LIBE}/070.usermgmt/useradd                                  \
	${BSDCFG_LIBE}/070.usermgmt/userdel                                  \
	${BSDCFG_LIBE}/070.usermgmt/useredit                                 \
	${BSDCFG_LIBE}/070.usermgmt/userinput                                \
	${BSDCFG_LIBE}/070.usermgmt/usermgmt                                 \
	${BSDCFG_LIBE}/080.console/INDEX                                     \
	${BSDCFG_LIBE}/080.console/USAGE                                     \
	${BSDCFG_LIBE}/080.console/console                                   \
	${BSDCFG_LIBE}/080.console/font                                      \
	${BSDCFG_LIBE}/080.console/include/messages.subr                     \
	${BSDCFG_LIBE}/080.console/keymap                                    \
	${BSDCFG_LIBE}/080.console/repeat                                    \
	${BSDCFG_LIBE}/080.console/saver                                     \
	${BSDCFG_LIBE}/080.console/screenmap                                 \
	${BSDCFG_LIBE}/080.console/ttys                                      \
	${BSDCFG_LIBE}/090.timezone/INDEX                                    \
	${BSDCFG_LIBE}/090.timezone/USAGE                                    \
	${BSDCFG_LIBE}/090.timezone/include/messages.subr                    \
	${BSDCFG_LIBE}/090.timezone/timezone                                 \
	${BSDCFG_LIBE}/110.mouse/INDEX                                       \
	${BSDCFG_LIBE}/110.mouse/USAGE                                       \
	${BSDCFG_LIBE}/110.mouse/disable                                     \
	${BSDCFG_LIBE}/110.mouse/enable                                      \
	${BSDCFG_LIBE}/110.mouse/flags                                       \
	${BSDCFG_LIBE}/110.mouse/include/messages.subr                       \
	${BSDCFG_LIBE}/110.mouse/mouse                                       \
	${BSDCFG_LIBE}/110.mouse/port                                        \
	${BSDCFG_LIBE}/110.mouse/type                                        \
	${BSDCFG_LIBE}/120.networking/INDEX                                  \
	${BSDCFG_LIBE}/120.networking/USAGE                                  \
	${BSDCFG_LIBE}/120.networking/defaultrouter                          \
	${BSDCFG_LIBE}/120.networking/devices                                \
	${BSDCFG_LIBE}/120.networking/hostname                               \
	${BSDCFG_LIBE}/120.networking/include/messages.subr                  \
	${BSDCFG_LIBE}/120.networking/nameservers                            \
	${BSDCFG_LIBE}/120.networking/networking                             \
	${BSDCFG_LIBE}/130.security/INDEX                                    \
	${BSDCFG_LIBE}/130.security/USAGE                                    \
	${BSDCFG_LIBE}/130.security/include/messages.subr                    \
	${BSDCFG_LIBE}/130.security/include/securelevel.hlp                  \
	${BSDCFG_LIBE}/130.security/kern_securelevel                         \
	${BSDCFG_LIBE}/130.security/security                                 \
	${BSDCFG_LIBE}/140.startup/INDEX                                     \
	${BSDCFG_LIBE}/140.startup/USAGE                                     \
	${BSDCFG_LIBE}/140.startup/include/messages.subr                     \
	${BSDCFG_LIBE}/140.startup/misc                                      \
	${BSDCFG_LIBE}/140.startup/rcadd                                     \
	${BSDCFG_LIBE}/140.startup/rcconf                                    \
	${BSDCFG_LIBE}/140.startup/rcdelete                                  \
	${BSDCFG_LIBE}/140.startup/rcedit                                    \
	${BSDCFG_LIBE}/140.startup/rcvar                                     \
	${BSDCFG_LIBE}/140.startup/startup                                   \
	${BSDCFG_LIBE}/150.ttys/INDEX                                        \
	${BSDCFG_LIBE}/150.ttys/USAGE                                        \
	${BSDCFG_LIBE}/150.ttys/include/messages.subr                        \
	${BSDCFG_LIBE}/150.ttys/ttys                                         \
	${BSDCFG_LIBE}/USAGE                                                 \
	${BSDCFG_LIBE}/dot/INDEX                                             \
	${BSDCFG_LIBE}/dot/USAGE                                             \
	${BSDCFG_LIBE}/dot/dot                                               \
	${BSDCFG_LIBE}/dot/include/messages.subr                             \
	${BSDCFG_LIBE}/include/bsdconfig.hlp                                 \
	${BSDCFG_LIBE}/include/media.hlp                                     \
	${BSDCFG_LIBE}/include/messages.subr                                 \
	${BSDCFG_LIBE}/include/network_device.hlp                            \
	${BSDCFG_LIBE}/include/options.hlp                                   \
	${BSDCFG_LIBE}/include/tcp.hlp                                       \
	${BSDCFG_LIBE}/include/usage.hlp                                     \
	${BSDCFG_SHARE}/common.subr                                          \
	${BSDCFG_SHARE}/device.subr                                          \
	${BSDCFG_SHARE}/dialog.subr                                          \
	${BSDCFG_SHARE}/media/any.subr                                       \
	${BSDCFG_SHARE}/media/cdrom.subr                                     \
	${BSDCFG_SHARE}/media/common.subr                                    \
	${BSDCFG_SHARE}/media/directory.subr                                 \
	${BSDCFG_SHARE}/media/dos.subr                                       \
	${BSDCFG_SHARE}/media/floppy.subr                                    \
	${BSDCFG_SHARE}/media/ftp.subr                                       \
	${BSDCFG_SHARE}/media/http.subr                                      \
	${BSDCFG_SHARE}/media/httpproxy.subr                                 \
	${BSDCFG_SHARE}/media/network.subr                                   \
	${BSDCFG_SHARE}/media/nfs.subr                                       \
	${BSDCFG_SHARE}/media/options.subr                                   \
	${BSDCFG_SHARE}/media/tcpip.subr                                     \
	${BSDCFG_SHARE}/media/ufs.subr                                       \
	${BSDCFG_SHARE}/media/usb.subr                                       \
	${BSDCFG_SHARE}/mustberoot.subr                                      \
	${BSDCFG_SHARE}/networking/common.subr                               \
	${BSDCFG_SHARE}/networking/device.subr                               \
	${BSDCFG_SHARE}/networking/hostname.subr                             \
	${BSDCFG_SHARE}/networking/ipaddr.subr                               \
	${BSDCFG_SHARE}/networking/media.subr                                \
	${BSDCFG_SHARE}/networking/netmask.subr                              \
	${BSDCFG_SHARE}/networking/resolv.subr                               \
	${BSDCFG_SHARE}/networking/routing.subr                              \
	${BSDCFG_SHARE}/networking/services.subr                             \
	${BSDCFG_SHARE}/packages/categories.subr                             \
	${BSDCFG_SHARE}/packages/index.subr                                  \
	${BSDCFG_SHARE}/packages/packages.subr                               \
	${BSDCFG_SHARE}/password/password.subr                               \
	${BSDCFG_SHARE}/script.subr                                          \
	${BSDCFG_SHARE}/startup/rcconf.subr                                  \
	${BSDCFG_SHARE}/startup/rcedit.subr                                  \
	${BSDCFG_SHARE}/startup/rcvar.subr                                   \
	${BSDCFG_SHARE}/strings.subr                                         \
	${BSDCFG_SHARE}/struct.subr                                          \
	${BSDCFG_SHARE}/sysrc.subr                                           \
	${BSDCFG_SHARE}/timezone/continents.subr                             \
	${BSDCFG_SHARE}/timezone/countries.subr                              \
	${BSDCFG_SHARE}/timezone/iso3166.subr                                \
	${BSDCFG_SHARE}/timezone/menus.subr                                  \
	${BSDCFG_SHARE}/timezone/zones.subr                                  \
	${BSDCFG_SHARE}/usermgmt/group_input.subr                            \
	${BSDCFG_SHARE}/usermgmt/user_input.subr                             \
	${BSDCFG_SHARE}/variable.subr

PLIST_DIRS=	${BSDCFG_LIBE}/020.docsinstall/include \
		${BSDCFG_LIBE}/020.docsinstall         \
		${BSDCFG_LIBE}/030.packages/include    \
		${BSDCFG_LIBE}/030.packages            \
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
		${BSDCFG_SHARE}/media                  \
		${BSDCFG_SHARE}/networking             \
		${BSDCFG_SHARE}/packages               \
		${BSDCFG_SHARE}/password               \
		${BSDCFG_SHARE}/startup                \
		${BSDCFG_SHARE}/timezone               \
		${BSDCFG_SHARE}/usermgmt               \
		${BSDCFG_SHARE}                        \
		share/examples/bsdconfig

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 900030
IGNORE=		requires FreeBSD 9.0 or later
.endif

post-patch:
	@${GREP} -Ilrs '^BSDCFG_LIBE=' ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} \
		-e 's|^\(BSDCFG_LIBE="\)[^"]*\(.*\)|\1${PREFIX}/libexec/${PORTNAME}\2|'
	@${GREP} -Ilrs '^BSDCFG_LIBE=' ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} \
		-e 's|^\(BSDCFG_LOCAL_LIBE="\)[^"]*\(.*\)|\1${PREFIX}/libexec/${PORTNAME}\2|'
	@${GREP} -Ilrs '^BSDCFG_SHARE=' ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} \
		-e 's|^\(BSDCFG_SHARE=\).*|\1"${PREFIX}/share/${PORTNAME}"|'
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
