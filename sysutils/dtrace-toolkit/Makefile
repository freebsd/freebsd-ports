PORTNAME=	dtrace-toolkit
PORTVERSION=	1.0
PORTREVISION=	7
CATEGORIES=	sysutils

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Collection of useful scripts for DTrace

LICENSE=	CDDL
LICENSE_FILE=	${WRKSRC}/Docs/cddl1.txt

USES=		perl5 python shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	opendtrace
GH_PROJECT=	toolkit
GH_TAGNAME=	ec23e25c8995bfa50cd7c0058129f1f489fdabb4
USE_RUBY=	yes
SHEBANG_FILES=	Apps/shellsnoop \
		Code/Perl/func_abc.pl \
		Code/Perl/func_malloc.pl \
		Code/Perl/func_slow.pl \
		Code/Perl/hello.pl \
		Code/Perl/hello_strict.pl \
		Code/Python/func_abc.py \
		Code/Python/func_slow.py \
		Code/Ruby/func_abc.rb \
		Code/Ruby/func_slow.rb \
		Code/Shell/func_abc.sh \
		Code/Shell/func_slow.sh \
		Code/Shell/func_waste.sh \
		Disk/diskhits \
		Disk/iopending \
		FS/vopstat \
		Include/test.ksh \
		Kernel/cpudists \
		Kernel/cputimes \
		Kernel/dnlcstat \
		Mem/xvmstat \
		Net/connections \
		Net/tcpsnoop \
		Net/tcpsnoop_snv \
		Net/tcptop \
		Net/tcptop_snv \
		Proc/dappprof \
		Proc/dapptrace \
		Proc/fddist \
		Proc/lastwords \
		Proc/pfilestat \
		Proc/sampleproc \
		Proc/topsysproc \
		System/topsyscall \
		Zones/zvmstat \
		dexplorer \
		dtruss \
		dvmstat \
		errinfo \
		execsnoop \
		hotkernel \
		hotuser \
		install \
		iopattern \
		iosnoop \
		iotop \
		opensnoop \
		procsystime \
		rwsnoop \
		rwtop \
		statsnoop
SHEBANG_LANG=	sh
sh_OLD_CMD=	/usr/bin/sh ./sh
sh_CMD=		${SH}
perl_OLD_CMD=	\\./perl
ruby_OLD_CMD=	\\./ruby

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
		${STAGEDIR}${MAN1PREFIX}/man/man1/${MANPAGE}.1
.endfor
	${ECHO_CMD} 'MANPATH ${DATADIR}/Man' > ${STAGEDIR}${PREFIX}/etc/man.d/${PORTNAME}.conf

.include <bsd.port.mk>
