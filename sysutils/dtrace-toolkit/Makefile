PORTNAME=	dtrace-toolkit
PORTVERSION=	1.0
PORTREVISION=	11
CATEGORIES=	sysutils

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Collection of useful scripts for DTrace
WWW=		https://github.com/opendtrace/toolkit

LICENSE=	CDDL
LICENSE_FILE=	${WRKSRC}/Docs/cddl1.txt

RUN_DEPENDS=	ksh93:shells/ksh

USES=		perl5 python ruby shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	opendtrace
GH_PROJECT=	toolkit
GH_TAGNAME=	ec23e25c8995bfa50cd7c0058129f1f489fdabb4
SHEBANG_FILES=	Apps/shellsnoop Code/Perl/func_abc.pl Code/Perl/func_malloc.pl \
		Code/Perl/func_slow.pl Code/Perl/hello.pl \
		Code/Perl/hello_strict.pl Code/Python/func_abc.py \
		Code/Python/func_slow.py Code/Ruby/func_abc.rb \
		Code/Ruby/func_slow.rb Code/Shell/func_abc.sh \
		Code/Shell/func_slow.sh Code/Shell/func_waste.sh dexplorer \
		Disk/diskhits Disk/iopending dtruss dvmstat errinfo execsnoop \
		FS/vopstat hotkernel hotuser Include/test.ksh install iopattern \
		iosnoop iotop Kernel/cpudists Kernel/cputimes Kernel/dnlcstat \
		Mem/xvmstat Net/connections Net/tcpsnoop Net/tcpsnoop_snv \
		Net/tcptop Net/tcptop_snv opensnoop Proc/dappprof \
		Proc/dapptrace Proc/fddist Proc/lastwords Proc/pfilestat \
		Proc/sampleproc Proc/topsysproc procsystime rwsnoop rwtop \
		statsnoop System/topsyscall Zones/zvmstat
SHEBANG_LANG=	sh
sh_OLD_CMD=	/usr/bin/sh ./sh
sh_CMD=		${SH}
perl_OLD_CMD=	\\./perl
ruby_OLD_CMD=	\\./ruby

MANDIRS=	${DATADIR}/Man/man1m
NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
# lstat calls are no longer available on 12.0+
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-dtruss
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${TAR} --exclude '*.orig' -cf - . ) | \
		(cd ${STAGEDIR}${DATADIR}/ && ${TAR} xvf -)
	${RLN} ${STAGEDIR}${DATADIR}/dtruss ${STAGEDIR}${PREFIX}/bin/dtruss
	${RLN} ${STAGEDIR}${DATADIR}/hotkernel ${STAGEDIR}${PREFIX}/bin/hotkernel
	${RLN} ${STAGEDIR}${DATADIR}/procsystime ${STAGEDIR}${PREFIX}/bin/procsystime
	${RLN} ${STAGEDIR}${DATADIR}/opensnoop ${STAGEDIR}${PREFIX}/bin/opensnoop
	${RLN} ${STAGEDIR}${DATADIR}/Apps/shellsnoop ${STAGEDIR}${PREFIX}/bin/shellsnoop

.for MANPAGE in dtruss hotkernel procsystime opensnoop shellsnoop
	${RLN} ${STAGEDIR}${DATADIR}/Man/man1m/${MANPAGE}.1m \
		${STAGEDIR}${PREFIX}/share/man/man1/${MANPAGE}.1
.endfor
	${ECHO_CMD} 'MANPATH ${DATADIR}/Man' > ${STAGEDIR}${PREFIX}/etc/man.d/${PORTNAME}.conf

.include <bsd.port.mk>
