# New ports collection makefile for: StarOffice 5.2 for Portuguese
# Date created:		Wed Jan 2 22:02:53 BRST 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	staroffice
PORTVERSION=	5.2
PORTREVISION=	2
CATEGORIES=	portuguese editors linux
MASTER_SITES=	http://ftp.ceat.net/pub/linux/text/office/star_office-5.2/ \
		ftp://ftp.puc-rio.br/pub/StarOffice52/ \
		http://ftp.linux.dct.ufms.br/software/office/staroffice/ \
		http://projecto-oasis.cx/ftp/linux/openoffice/ \
		ftp://sunsite.uio.no/pub/sun/sun-patches/ \
		ftp://ftp.hu-berlin.de/pub/mirrors/sunsolve.sun.com/pub/patches/
DISTNAME=	so-5_2-ga-bin-linux-pt.bin
DISTFILES=	109939-03.tar.Z
.if !defined(WITH_CDROM)
DISTFILES+=	so-5_2-ga-bin-linux-pt.bin
.if defined(WITH_ADABAS)
DISTFILES+=	soa-5_2-ga-bin-linux-pt.bin
.endif
.endif
EXTRACT_ONLY=	109939-03.tar.Z

MAINTAINER=	mbr@FreeBSD.org
COMMENT=	Sistema integrado de processador de texto/planilha/e muito mais

FETCH_DEPENDS=	${LINUX_BASE_PORT}

ONLY_FOR_ARCHS=	i386
USE_LINUX=	yes
USE_X_PREFIX=	yes
NO_CDROM=	'Deve ser obtido diretamente do site da Sun via interface www'
CD_MOUNTPT=	'/cdrom'
IS_INTERACTIVE=	yes
NO_BUILD=	yes
USE_PERL5_BUILD=yes
DIST_SUBDIR=	staroffice52
WRKSRC=		${WRKDIR}/office52
TMPDIR=		${WRKDIR}/tmp
LD_PATH=	${TMPDIR}:${WRKSRC}:${LINUXBASE}/lib:${LINUXBASE}/usr/lib
INSTDB.INS=	${PREFIX}/office52/program/instdb.ins
SUNSOLVE=	${WRKDIR}/109939-03
ADABAS_DIST=	soa-5_2-ga-bin-linux-pt.bin

.include <bsd.port.pre.mk>

SIZE!=		/bin/df -k . | ${TAIL} -n 1 | ${AWK} '{print $$4}'
LINPROCFS!=	/sbin/mount | ${GREP} linprocfs | ${AWK} '{print $1}'

pre-fetch:
.if ${LINPROCFS}
	@${ECHO}
	@${ECHO} Verifique se linprocfs está executando: SIM
.else
	@${ECHO} -----------------------------------------------------------
	@${ECHO}
	@${ECHO} O programa de instalação do Staroffice precisa de
	@${ECHO} um linprocfs executando, o qual não está ativo em
	@${ECHO} teu sistema. Por favor, leia a página de manual
	@${ECHO} linprocfs\(5\) e adicione a seguinte linha a /etc/fstab:
	@${ECHO}
	@${ECHO} linproc /compat/linux/proc linprocfs rw 0 0
	@${ECHO}
	@${ECHO} -----------------------------------------------------------
	@${FALSE}
.endif
.if ${OSVERSION} < 410000
	@${ECHO}
	@${ECHO} OS-VERSION ${OSVERSION}
	@${ECHO}
	@${ECHO} Staroffice depende de uma correção para
	@${ECHO} linguagem script em
	@${ECHO} /usr/src/sys/i386/linux/linux_sysvec.c
	@${ECHO} \(revisão 1.55.2.1 ou maior\)
	@${ECHO}
	@${ECHO} Por favor, atualize seu sistema para FreeBSD 4.1
	@${ECHO}
	@${FALSE}
.endif
.if ${SIZE} < 250000
	@${ECHO}
	@${ECHO} Há pouco espaço livre em disco em seu diretório
	@${ECHO} de ports. Staroffice necessita de, ao menos, 250MB
	@${ECHO} de espaço livre em disco para desempacotar.
	@${FALSE}
.endif
.if !defined(WITH_ADABAS)
	@${ECHO}
	@${ECHO} Caso deseje instalar Staroffice com suporte para
	@${ECHO} banco de dados ADABAS, cancele esta instalação
	@${ECHO} agora e inicie make novamente com WITH_ADABAS=SIM.
	@${ECHO}
.endif
.if defined(WITH_CDROM)
.if !exists(/cdrom/linux/office52/setup)
	@${ECHO}
	@${ECHO} Por favor, monte o CDROM do Sun StarOffice 5.2
	@${ECHO} em ${CD_MOUNTPT} e execute make novamente.
	@${ECHO}
	@${FALSE}
.endif
.endif

do-extract:
.if !defined(DISPLAY) || ${DISPLAY} == ""
	@${ECHO}
	@${ECHO} Não posso mostrar a interface gráfica:
	@${ECHO} Por favor, verifique sua variável DISPLAY.
	@${ECHO}
	@${FALSE}
.else
	@${MKDIR} ${WRKSRC}
	@${MKDIR} ${TMPDIR}
.if defined(WITH_CDROM)
.if !exists(${CD_MOUNTPT}/linux/office52/setup)
.if defined(WITH_ADABAS)
	@cd ${WRKSRC} && ${LN} -s ${CD_MOUNTPT}/linux/adabas/adabas .
	@cd ${WRKSRC} && ${LN} -s ${CD_MOUNTPT}/linux/adabas/f_0000 .
	@cd ${WRKSRC} && ${LN} -s ${CD_MOUNTPT}/linux/adabas/f_0001 .
.endif
	@${MKDIR} ${WRKSRC}
	@cd ${WRKSRC} && ${LN} -s ${CD_MOUNTPT}/linux/office52/* .
.endif
.else
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME} ${WRKSRC}
	@${CHMOD} 755 ${WRKSRC}/${DISTNAME}
.if defined(WITH_ADABAS)
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${ADABAS_DIST} ${WRKSRC}
	@${CHMOD} 755 ${WRKSRC}/${ADABAS_DIST}
.endif
	@cd ${WRKSRC}
	@SAL_IGNOREXERRORS=1 ${WRKSRC}/${DISTNAME} -extract ${WRKSRC}
	@${RM} ${WRKSRC}/${DISTNAME}
.endif
	@cd ../../
	@for file in ${EXTRACT_ONLY}; do \
		if ! (cd ${WRKDIR} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
		    ${DISTDIR}/${DIST_SUBDIR}/$$file ${EXTRACT_AFTER_ARGS}) ; \
		then \
			exit 1; \
		fi \
	done
.endif

post-configure:
	@${PERL} -pi -e 's|\r\n|\n|; \
		s|DefaultDestPath = "office52";|DefaultDestPath = "${PREFIX}/office52";|' \
		${WRKSRC}/setup.ins

do-install:
.if !defined(DISPLAY) || ${DISPLAY} == ""
	@${ECHO}
	@${ECHO_MSG} "Não posso mostrar a interface gráfica:"
	@${ECHO_MSG} "Por favor, verifique sua variável DISPLAY."
	@${ECHO}
	@${FALSE}
.else
.if exists(${LINUXBASE}/${PREFIX})
	@ ${LN} -fs ${LINUXBASE}/${PREFIX}/office52 ${PREFIX}/office52
.endif
	@${CAT} ${PKGMESSAGE}
	@-SAL_IGNOREXERRORS=1 PATH="/bin:${PATH}" TEMP=${TMPDIR} LD_LIBRARY_PATH=${LD_PATH} ${LINUXBASE}/bin/sh -c '${WRKSRC}/setup /net'
	@if [ -f ${PREFIX}/office52/program/setup ]; then \
		${ECHO_MSG} ; \
		${ECHO_MSG} Ignore a mensagem de erro. StarOffice5.2 foi instalado ; \
		${ECHO_MSG} com sucesso em seu sistema. ; \
		${ECHO_MSG} ; \
	else \
		${ECHO_MSG} ; \
		${ECHO_MSG} "Um erro ocorreu durante a instalação do StarOffice5.2. Por favor, envie e-mail" ; \
		${ECHO_MSG} "(em inglês) com a saída de depuração e algumas informações sobre" ; \
		${ECHO_MSG} seu ambiente FreeBSD para mb@imp.ch. Obrigado. ; \
		${ECHO_MSG} ; \
		${FALSE} ; \
	fi
	@${ECHO_MSG} "===>   Aplicando correções sunsolve a ${PKGNAME}"
	@for file in ${SUNSOLVE}/* ; do \
		${CP} -Rv $$file ${PREFIX}/office52/ ; \
	done
.endif
# XXX: This is missing a "${BRANDELF} -t Linux <executables>".

post-install:
.for file in setup soffice
	@${PERL} -pi -e 's|(/bin/sh)|${LINUXBASE}/\1|; \
		s|^(# \(c\).+?Sun Microsystems,? Inc\.)$$|\1\n#fix coredump on remote DISPLAY (IRIX)\nexport SAL_IGNOREXERRORS=1\n|' ${PREFIX}/office52/program/${file}
.endfor
	@${CP} ${INSTDB.INS} ${INSTDB.INS}.orig
	@${SED} -e 's%DefaultDestPath = "${PREFIX}/office52%DefaultDestPath = "office52%' \
	    < ${INSTDB.INS}.orig > ${INSTDB.INS}
	@${RM} ${INSTDB.INS}.orig

install-user:
	@-SAL_IGNOREXERRORS=1 PATH="/bin:${PATH}" ${LINUXBASE}/bin/sh -c \
		${LOCALBASE}/office52/program/setup

.include <bsd.port.post.mk>
