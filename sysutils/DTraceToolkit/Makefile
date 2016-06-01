# Created by: Steven Kreuzer <steven@exit2shell.com>
# $FreeBSD$

PORTNAME=	dtrace-toolkit
PORTVERSION=	1.0
CATEGORIES=	sysutils

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Collection of useful scripts for DTrace

USE_GITHUB=	yes
GH_ACCOUNT=	opendtrace
GH_PROJECT=	toolkit
GH_TAGNAME=	f36d00b
USES=		shebangfix
SHEBANG_LANG=	sh
sh_OLD_CMD=	/usr/bin/sh ./sh
sh_CMD=		${SH}
perl_OLD_CMD=	\\./perl
ruby_OLD_CMD=	\\./ruby
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

NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}; ${TAR} --exclude '*.orig' -cf - . ) | \
		(cd ${STAGEDIR}${DATADIR}/; ${TAR} xvf -)
	${LN} -fs ${DATADIR}/hotkernel ${STAGEDIR}${PREFIX}/bin/hotkernel
	${LN} -fs ${DATADIR}/procsystime ${STAGEDIR}${PREFIX}/bin/procsystime
	${LN} -fs ${DATADIR}/opensnoop ${STAGEDIR}${PREFIX}/bin/opensnoop
	${LN} -fs ${DATADIR}/Apps/shellsnoop ${STAGEDIR}${PREFIX}/bin/shellsnoop

.include <bsd.port.mk>
