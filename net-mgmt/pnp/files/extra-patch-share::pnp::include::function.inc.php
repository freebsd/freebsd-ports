--- share/pnp/include/function.inc.php.orig	2008-06-18 12:02:41.000000000 +0400
+++ share/pnp/include/function.inc.php	2008-08-16 23:35:30.000000000 +0400
@@ -819,114 +819,15 @@
 }
 
 function doPDF($display,$data) {
-	require ('fpdi.php');
-	global $NAGIOS;
-	global $conf;
-        if(file_exists($conf['background_pdf'])){
-                $use_bg=1;
-        }
-	class PDF extends FPDI {
-		//Page header
-		function Header() {
-			//Arial bold 10 
-			$this->SetFont('Arial', 'B', 10);
-			//Move to the right
-			$this->Cell(80);
-			//Title
-			$this->Cell(30, 10, _PDFTITLE, 0, 1, 'C');
-			//Line break
-			#$this->Ln(20);
-		}
-
-		//Page footer
-		function Footer() {
-			//Position at 1.5 cm from bottom
-			$this->SetY(-20);
-			//Arial italic 8
-			$this->SetFont('Arial', 'I', 8);
-			//Page number
-			$this->Cell(0, 10, _PDFPAGE . $this->PageNo() . '/{nb}', 0, 0, 'C');
-		}
-	}
-
-	$pdf =& new PDF('P', 'mm', 'A4');
-	$pdf->AliasNbPages();
-        $pdf->SetAutoPageBreak('off');
-	$pdf->SetMargins(12.5,25,10);
-	$pdf->AddPage();
-	if($use_bg){
-		$pdf->setSourceFile($conf['background_pdf']);
-		$tplIdx = $pdf->importPage(1,'/MediaBox');
-		$pdf->useTemplate($tplIdx);
-	}
-	$pdf->SetCreator('Created with PNP');
-	$pdf->SetAuthor($_PHP['REMOTE_USER']);
-	$pdf->SetFont('Arial', '', 10);
-	$pdf->Cell(120, 4, '', 0, 1, 'L');
-	if($display == "service"){
-		foreach($data as $d) {
-			if ($pdf->GetY() > 220) {
-				$pdf->AddPage();
-				if($use_bg){$pdf->useTemplate($tplIdx);}	
-			}
-
-			$pdf->SetFont('Arial', '', 10);
-			$pdf->CELL(120, 5, $d["n_hostname"]." / ".$d["n_servicedesc"] , 0, 1);
-			$pdf->SetFont('Arial', '', 8);
-			$pdf->CELL(120, 5, $d["view_title"]. " (" . $d["f_start"]." - ".$d["f_end"].")", 0, 1);
-
-			$img = saveImage($d['rrd_opts']);
-                        $Y = $pdf->GetY();
-			$cell_height = ($img['height'] * 0.23);
-			$cell_width = ($img['width'] * 0.23);
-                        $pdf->Image($img['name'], 12.5, $Y, $cell_width, $cell_height, 'PNG');
-                        $pdf->CELL(120, $cell_height, '', 0, 1);
-			unlink($img['name']);
-		}
-	}
-	if($display == "page"){
-                foreach($data as $d) {
-			if ($pdf->GetY() > 220) {
-				$pdf->AddPage();
-				if($use_bg){$pdf->useTemplate($tplIdx);}
-			}
-
-			$pdf->SetFont('Arial', '', 10);
-			$pdf->CELL(120, 5, $d["hostname"]." / ".$d["servicedesc"] , 0, 1);
-			$pdf->SetFont('Arial', '', 8);
-			$pdf->CELL(120, 5, $d["f_start"]." - ".$d["f_end"], 0, 1);
-
-			$img = saveImage($d['rrd_opts']);
-                        $Y = $pdf->GetY();
-			$cell_height = ($img['height'] * 0.23);
-			$cell_width = ($img['width'] * 0.23);
-                        $pdf->Image($img['name'], 12.5, $Y, $cell_width, $cell_height, 'PNG');
-                        $pdf->CELL(120, $cell_height, '', 0, 1);
-			unlink($img['name']);
-               }
-        }
-        if($display == "host_list"){
-                foreach($data as $d) {
-                        if ($pdf->GetY() > 220) {
-                                $pdf->AddPage();
-				if($use_bg){$pdf->useTemplate($tplIdx);}
-                        }
-                        $pdf->SetFont('Arial', '', 10);
-                        $pdf->CELL(120, 7, $d["hostname"]." / ".$d["servicedesc"] , 0, 1);
-                        $pdf->SetFont('Arial', '', 8);
-                        $pdf->CELL(120, 5, $d["f_start"]." - ".$d["f_end"], 0, 1);
-
-			$img = saveImage($d['rrd_opts']);
-                        $Y = $pdf->GetY();
-			$cell_height = ($img['height'] * 0.23);
-			$cell_width = ($img['width'] * 0.23);
-                        $pdf->Image($img['name'], 12.5, $Y, $cell_width, $cell_height, 'PNG');
-                        $pdf->CELL(120, $cell_height, '', 0, 1);
-			unlink($img['name']);
-                }
-        }
-
-	$pdf->Output();
+	print "<html>\n";
+	print "<head>\n";
+	print "<title>Failed</title>\n";
+	print "</head>\n";
+	print "<body>\n";
+	print "<h1>Failed</h1>\n";
+	print "</body>\n";
+	print "<html>\n";
+	exit(0);
 }
 
 function doStrip($string) {
@@ -1173,23 +1074,6 @@
 }
 
 function doPDFIcon($type){
-	global $hostname;
-	global $servicedesc;
-	global $start;
-	global $end;
-	global $source;
-	global $view;
-	global $display;
-	global $page;
-
-	switch($type){
-		case "PAGE":
-			print "<a href=\"index.php?page=$page&display=$display&view=$view&do=pdf\"><img src=\"images/pdf.png\" HEIGHT=\"32px\" WIDTH=\"32px\" title=\"Display PDF\" ></a>\n";
-			break;
-		default:
-			print "<a href=\"index.php?host=$hostname&srv=$servicedesc&display=$display&view=$view&source=$source&end=$end&start=$start&do=pdf\"><img src=\"images/pdf.png\" HEIGHT=\"32px\" WIDTH=\"32px\" title=\"Display PDF\" ></a>\n";
-			break;
-	}
 }
 
 function doXMLIcon(){
