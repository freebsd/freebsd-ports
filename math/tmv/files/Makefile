# $FreeBSD$

# lib/libtmv.so
LST1= TMV_Vector TMV_MultVV TMV_AddVV TMV_MultXV TMV_BaseMatrix TMV_Matrix TMV_MultXM TMV_AddMM TMV_MultMV TMV_Rank1_VVM TMV_MultMM_CCC TMV_MultMM_CRC TMV_MultMM_RCC TMV_MultMM_Block TMV_IntegerDet TMV_DiagMatrix TMV_MultDV TMV_AddDM TMV_MultDM TMV_TriMatrix TMV_TriDiv TMV_MultUV TMV_MultXU TMV_AddUU TMV_MultUM TMV_MultUL TMV_MultUU TMV_MultDU TMV_Givens TMV_Householder TMV_LUD TMV_LUDecompose TMV_LUDiv TMV_LUInverse TMV_QRD TMV_QRDecompose TMV_QRDiv TMV_PackedQ TMV_QRInverse TMV_GetQFromQR TMV_QRUpdate TMV_QRDowndate TMV_QRPD TMV_SVD TMV_SVDecompose TMV_SVDecompose_Bidiag TMV_SVDecompose_QR TMV_SVDiv TMV_TriDiv_V TMV_TriDiv_M TMV_TriDiv_L TMV_TriInverse TMV_MultMM TMV_MultMM_OpenMP TMV_SVDecompose_DC TMV_QRPDecompose
LIB1=      libtmv.so.0

# lib/libtmv_symband.so
LST2= TMV_BandMatrix TMV_MultBV TMV_MultXB TMV_AddBB TMV_MultBM TMV_MultBB TMV_BandIntegerDet TMV_SymMatrix TMV_MultSV TMV_AddSS TMV_Rank1_VVS TMV_Rank2_VVS TMV_MultSM TMV_RankK_MMS TMV_Rank2K_MMS TMV_RankK_ULS TMV_RankK_LUS TMV_SymMultMMS TMV_SymIntegerDet TMV_SymBandMatrix TMV_MultsBV TMV_AddsBsB TMV_MultsBM TMV_MultsBB TMV_SymBandIntegerDet TMV_BandLUD TMV_BandLUDecompose TMV_BandLUDiv TMV_BandLUInverse TMV_BandTriDiv_V TMV_BandTriDiv_M TMV_BandQRD TMV_BandQRDecompose TMV_BandQRDiv TMV_BandQRInverse TMV_BandSVD TMV_BandSVDecompose TMV_SymHouseholder TMV_SymLDLD TMV_SymLDLDecompose TMV_SymLDLDiv TMV_SymLDLInverse TMV_SymLDLPseudo TMV_SymSquare TMV_SymCHD TMV_SymCHDecompose TMV_SymCHDiv TMV_SymCHInverse TMV_SymSVD TMV_SymSVInverse TMV_IsNaN TMV_SymSVDecompose_Tridiag TMV_SymSVDecompose_QR TMV_SymBandCHD TMV_SymBandCHDecompose TMV_SymBandCHDiv TMV_SymBandCHInverse TMV_SymBandSVD TMV_SymBandSVDecompose TMV_SymSVDecompose_DC TMV_SymSVDecompose
LIB2=      libtmv_symband.so.0

CXXFLAGS+= -I../include -fopenmp -fPIC -DTMV_NDEBUG -DFBLAS -DNOLAP
LDFLAGS+=  -lblas

SRCS1=  $(addsuffix .cpp, $(LST1))
SRCS2=  $(addsuffix .cpp, $(LST2))
OBJS1=  $(addsuffix .o, $(LST1))
OBJS2=  $(addsuffix .o, $(LST2))

all: $(LIB1) $(LIB2)

$(LIB1): $(OBJS1)
	$(CXX) -shared -fopenmp -Wl,-soname,$(LIB1) $(LDFLAGS) -o $(LIB1) $(OBJS1)

$(LIB2): $(OBJS2)
	$(CXX) -shared -fopenmp -Wl,-soname,$(LIB2) $(LDFLAGS) -o $(LIB2) $(OBJS2)

install:
	mkdir -p $(DESTDIR)$(PREFIX)/include/tmv $(DESTDIR)$(PREFIX)/lib
	install ../include/TMV*.h $(DESTDIR)$(PREFIX)/include
	install ../include/tmv/TMV*.h $(DESTDIR)$(PREFIX)/include/tmv
	${BSD_INSTALL_LIB} $(LIB1) $(DESTDIR)$(PREFIX)/lib
	${BSD_INSTALL_LIB} $(LIB2) $(DESTDIR)$(PREFIX)/lib
	cd $(DESTDIR)$(PREFIX)/lib && ln -s $(LIB1) $(LIB1:.0=) && ln -s $(LIB2) $(LIB2:.0=)
