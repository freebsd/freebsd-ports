# Updated ports collection makefile for:   click
# Date created:        3 Nov 2001
# Whom:                gnn
#
# $FreeBSD$
#

PORTNAME=	click
PORTVERSION=	1.2.3
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.pdos.lcs.mit.edu/click/

MAINTAINER=	gnn@neville-neil.com
COMMENT=	The Click Modular Router

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

MANCOMPRESSED=	no
MAN1=	click.1 click-align.1 click-combine.1 click-devirtualize.1 \
	click-fastclassifier.1 click-flatten.1 click-install.1 \
	click-mkmindriver.1 click-uncombine.1 click-undead.1 \
	click-uninstall.1 click-xform.1
MAN5=	click.5
MAN7=	elementdoc.7
MAN8=	click.o.8
MANN=	FTPPortMapper.n ARPFaker.n ARPQuerier.n ARPResponder.n \
	EnsureEther.n EtherEncap.n EtherMirror.n HostEtherFilter.n \
	CheckICMPHeader.n ICMPError.n ICMPPingResponder.n ICMPPingRewriter.n \
	ICMPRewriter.n ICMPSendPings.n CheckIPHeader.n CheckIPHeader2.n \
	DecIPTTL.n FixIPSrc.n GetIPAddress.n IPAddrRewriter.n IPClassifier.n \
	IPEncap.n IPFilter.n IPFragmenter.n IPGWOptions.n IPInputCombo.n \
	IPMirror.n IPOutputCombo.n IPPrint.n IPRateMonitor.n \
	IPRewriterPatterns.n LookupIPRoute.n LookupIPRoute2.n \
	LookupIPRouteLinux.n MarkIPCE.n MarkIPHeader.n RIPSend.n \
	RoundRobinIPMapper.n SetIPAddress.n SetIPChecksum.n SetIPDSCP.n \
	SetRandIPAddress.n StoreIPAddress.n StripIPHeader.n UnstripIPHeader.n \
	AddressInfo.n Align.n AlignmentInfo.n AverageCounter.n \
	BandwidthMeter.n BandwidthShaper.n Burster.n BandwidthRatedSplitter.n \
	BandwidthRatedUnqueue.n CheckCRC32.n CheckLength.n CheckPaint.n \
	Classifier.n CompareBlock.n Counter.n DelayShaper.n DelayUnqueue.n \
	Discard.n DiscardNoFree.n DriverManager.n DropBroadcasts.n DRRSched.n \
	Error.n FrontDropQueue.n HashSwitch.n Idle.n \
	InfiniteSource.n Meter.n MSQueue.n Null.n PushNull.n PullNull.n \
	Null1.n Null2.n Null3.n Null4.n Null5.n Null6.n Null7.n Null8.n \
	Paint.n PaintTee.n PeekHandlers.n PokeHandlers.n Print.n PrioSched.n \
	ProbSplitter.n PullSwitch.n Queue.n QuitWatcher.n \
	RandomBitErrors.n RandomLossage.n RandomSource.n RatedSource.n \
	RatedSplitter.n RatedUnqueue.n RED.n RoundRobinSched.n \
	RoundRobinSwitch.n ScheduleInfo.n SetCRC32.n SetTimestamp.n Shaper.n \
	SpinlockAcquire.n SpinlockInfo.n SpinlockRelease.n StaticPullSwitch.n \
	StaticSwitch.n StrideSched.n StrideSwitch.n Strip.n Suppressor.n \
	Switch.n Tee.n PullTee.n TimedSink.n TimedSource.n Unqueue.n \
	Unqueue2.n Unstrip.n CheckTCPHeader.n CheckUDPHeader.n \
	DynamicUDPIPEncap.n IPRewriter.n SetTCPChecksum.n TCPRewriter.n \
	UDPIPEncap.n ChatterSocket.n ControlSocket.n FromDevice.u.n \
	FromDump.n KernelTap.n KernelHandlerProxy.n PrintOld.n \
	ToDevice.u.n ToDump.n elements.n AdaptiveRED.n IPReassembler.n \
	IPRouteTable.n StaticIPLookup.n LinuxIPLookup.n RadixIPLookup.n \
	RandomSample.n SetPacketType.n StripToNetworkHeader.n ProgressBar.n

CONFDIR=	${PREFIX}/etc/click/conf

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500113
BROKEN=         "Does not compile (bad C++ code)"
.endif

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/click
	@${STRIP_CMD} ${PREFIX}/bin/click-align
	@${STRIP_CMD} ${PREFIX}/bin/click-check
	@${STRIP_CMD} ${PREFIX}/bin/click-combine
	@${STRIP_CMD} ${PREFIX}/bin/click-uncombine
	@${STRIP_CMD} ${PREFIX}/bin/click-devirtualize
	@${STRIP_CMD} ${PREFIX}/bin/click-fastclassifier
	@${STRIP_CMD} ${PREFIX}/bin/click-flatten
	@${STRIP_CMD} ${PREFIX}/bin/click-mkmindriver
	@${STRIP_CMD} ${PREFIX}/bin/click-undead
	@${STRIP_CMD} ${PREFIX}/bin/click-xform
	@${MKDIR} ${CONFDIR}
	${INSTALL_DATA} ${WRKSRC}/conf/fake-iprouter.click ${CONFDIR}
	${INSTALL_DATA} ${WRKSRC}/conf/ip.clickpat ${CONFDIR}
	${INSTALL_DATA} ${WRKSRC}/conf/ip6ndadvertiser.click ${CONFDIR}
	${INSTALL_DATA} ${WRKSRC}/conf/ip6ndsolicitor.click ${CONFDIR}
	${INSTALL_DATA} ${WRKSRC}/conf/kernel.clickpat ${CONFDIR}
	${INSTALL_DATA} ${WRKSRC}/conf/mazu-nat.click ${CONFDIR}
	${INSTALL_DATA} ${WRKSRC}/conf/test-device.click ${CONFDIR}
	${INSTALL_DATA} ${WRKSRC}/conf/test-tap.click ${CONFDIR}
	${INSTALL_DATA} ${WRKSRC}/conf/test.click ${CONFDIR}
	${INSTALL_DATA} ${WRKSRC}/conf/test2.click ${CONFDIR}
	${INSTALL_DATA} ${WRKSRC}/conf/test3.click ${CONFDIR}
	${INSTALL_DATA} ${WRKSRC}/conf/udpgen.click ${CONFDIR}
	@echo
	@echo "----------------------------------------------------"
	@echo "Install complete, to try it out do the following:"
	@echo "cd ${PREFIX}/etc/click/conf"
	@echo "click test.click"
	@echo "You should see some output.  Now go read the papers and manual."
	@echo "----------------------------------------------------"
	@echo

.include <bsd.port.post.mk>
